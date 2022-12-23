/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int days = prices.size();

		// max profit at [day#][transaction#0..2][position#0..1]
		vector<vector<vector<int>>> profit(days, vector<vector<int>>(3, vector<int>(2)));

		// init base cases
		for (int i = 0; i < days; i++) {
			profit[i][0][0] = 0;
			profit[i][0][1] = INT_MIN;	// not possible with position hold without transaction

			profit[i][1][0] = 0;
			profit[i][1][1] = -prices[i];

			profit[i][2][0] = 0;
			profit[i][2][1] = -prices[i];
		}

		for (int day = 1; day < days; day++) {
			for (int trans = 2; trans >= 1; trans--) {
				profit[day][trans][0] = max(
											profit[day - 1][trans][0],
											profit[day - 1][trans][1] + prices[day]
										);
				profit[day][trans][1] = max(
											profit[day - 1][  trans  ][1],
											profit[day - 1][trans - 1][0] - prices[day]
										);
			}
		}
		return profit[days - 1][2][0];
	}
};
// @lc code=end
