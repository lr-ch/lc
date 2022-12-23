/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int days = prices.size();

		// profit[day#][position]
		vector<vector<int>> profit(days, vector<int>(2));

		// init base case
		profit[0][0] = 0;
		profit[0][1] = -prices[0];

		for (int day = 1; day < days; day++) {
			profit[day][0] = max(profit[day - 1][0], profit[day - 1][1] + prices[day] - fee);
			profit[day][1] = max(profit[day - 1][1], profit[day - 1][0] - prices[day]);
		}

		return profit[days - 1][0];
	}
};
// @lc code=end
