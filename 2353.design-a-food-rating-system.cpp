/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
class FoodRatings {
	struct Food {
		int rating;
		string name;

		Food(string n, int r) : name(n), rating(r) {}

		// sort() of priority_queue
		bool operator<(const Food& rhs) const {
			if (rhs.rating == rating) return name > rhs.name;
			return rating < rhs.rating;
		}
	};

	unordered_map<string, int> food_ratings;		// (food name, rating)
	unordered_map<string, string> food_cuisines;	// (food name, cuisine)
	unordered_map<string, priority_queue<Food>> cuisines_order;	// (cuisine, rating order)
public:
	FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		for (int i = 0; i < foods.size(); i++) {
			food_cuisines[foods[i]] = cuisines[i];
			food_ratings[foods[i]] = ratings[i];
			cuisines_order[cuisines[i]].push(Food(foods[i], ratings[i]));
		}
	}

	void changeRating(string food, int newRating) {
		food_ratings[food] = newRating;

		// we may have duplicated ratings to a single food,
		// it's ok, we will validate correctness on highestRated()
		cuisines_order[food_cuisines[food]].push(Food(food, newRating));
	}

	string highestRated(string cuisine) {
		Food candidate = cuisines_order[cuisine].top();

		// check if the rating matches record,
		// keep looking into correct food if the rating is not matched
		while (food_ratings[candidate.name] != candidate.rating) {
			cuisines_order[cuisine].pop();
			candidate = cuisines_order[cuisine].top();
		}
		return candidate.name;
	}
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end
