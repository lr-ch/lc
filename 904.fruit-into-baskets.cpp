/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
	unordered_map<int, int> basket;
public:
	int totalFruit(vector<int>& fruits) {
		if (fruits.size() < 2) return fruits.size();

		// initial state
		int left = 0, right = left + 1, res = 2;
		basket[fruits[left]]++;
		basket[fruits[right]]++;

		while (right + 1 < fruits.size()) {
			basket[fruits[++right]]++;

			// remove fruits
			while (basket.size() > 2) {
				basket[fruits[left]]--;

				// if the value is 0, remove the key
				// otherwise basket.size() always > 2
				if (basket[fruits[left]] == 0)
					basket.erase(fruits[left]);

				left++;
			}

			res = max(res, right - left + 1);
		}

		return res;
	}
};
// @lc code=end
