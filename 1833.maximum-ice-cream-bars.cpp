/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		sort(costs.begin(), costs.end());

		int total = 0, ans = 0;
		for (ans = 0; ans < costs.size(); ans++) {
			total += costs[ans];
			if (total > coins)
				break;
		}

		return ans;
	}
};
// @lc code=end
