/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution {
public:
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		vector<pair<int, int>> bags;
		for (int i = 0; i < capacity.size(); i++)
			bags.push_back(pair<int, int>(capacity[i], rocks[i]));
		sort(bags.begin(), bags.end(), [](const auto& a, const auto& b) {
			// prefer less remain capacity for "maximun" bags
			return a.first - a.second < b.first - b.second;
		});

		int totalBags = 0;
		for (auto b : bags) {
			// select number of rocks should be remain rocks or remain capacity
			int rocksToPutIn = min(additionalRocks, b.first - b.second);

			// put rocks into the bag
			if (rocksToPutIn > 0) {
				additionalRocks -= rocksToPutIn;
				b.second += rocksToPutIn;
			}

			// check whether the bag is full
			if (0 == b.first - b.second)
				totalBags++;
		}
		return totalBags;
	}
};
// @lc code=end

