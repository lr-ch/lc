/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0 || prices.empty()) return 0;

		int days = prices.size();
		// dp[days][k(transaction)][position(true or false)] <- profits
		vector<vector<vector<int>>> dp(days,
									   vector<vector<int>>(k + 1,
									   vector<int>(2, 0)));

		// init base cases
		for (int d = 0; d < days; d++) {
			dp[d][0][0] = 0;		// no profit with no transaction
			dp[d][0][1] = INT_MIN;	// not possible to hold position without transaction
		}

		// fill out dp table
		for (int i = 0; i < days; i++) {
			for (int j = k; j >= 1; j--) {
				// dealing with dp[-1][j][0 or 1]
				if (i == 0) {
					dp[i][j][0] = 0;			// no position, no profit
					dp[i][j][1] = -prices[i];	// profit is the cost the price at day#i
					continue;
				}

				// profits without position at day#i and transactions#j
				dp[i][j][0] = max(
					dp[i - 1][j][0],			// no position
					dp[i - 1][j][1] + prices[i]	// sell position and get profit
				);

				// profits with position at day#i and transactions#j
				dp[i][j][1] = max(
					dp[i - 1][j][1],				// keep position
					dp[i - 1][j - 1][0] - prices[i]	// buy position and cost prices at day#i
				);
			}
		}

		return dp[days - 1][k][0];
	}
};
// @lc code=end
