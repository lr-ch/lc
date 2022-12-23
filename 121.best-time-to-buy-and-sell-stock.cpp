/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int days = prices.size();

		// max profit at [i-th day][position]
		vector<vector<int>> profit(days, vector<int>(2));

		profit[0][0] = 0;
		profit[0][1] = -prices[0];

		for (int i = 1; i < days; i++) {
			profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i]);

			// only buy once
			profit[i][1] = max(profit[i - 1][1], -prices[i]);
		}
		return profit[days - 1][0];
	}
};
// @lc code=end
