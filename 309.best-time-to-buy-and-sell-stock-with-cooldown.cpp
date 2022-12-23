/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int days = prices.size();

		// max profit of day[i][position]
		vector<vector<int>> maxProfit(days, vector<int>(2));

		// base case for day#0
		maxProfit[0][0] = 0;				// no position at day#0
		maxProfit[0][1] = -prices[0];		// hold position at day#0

		// base case for day#1
		if (days > 1) {
			// no position at day#1
			maxProfit[1][0] = max(maxProfit[0][0], maxProfit[0][1] + prices[1]);

			// hold position at day#1
			maxProfit[1][1] = max(maxProfit[0][1], -prices[1]);
		}

		// start iteration from day#2
		for (int i = 2; i < days; i++) {
			// no position at day#i
			maxProfit[i][0] = max(maxProfit[i - 1][0], maxProfit[i - 1][1] + prices[i]);

			// hold position at day#i
			maxProfit[i][1] = max(maxProfit[i - 1][1], maxProfit[i - 2][0] - prices[i]);
		}

		return maxProfit[days - 1][0];
	}
};
// @lc code=end
