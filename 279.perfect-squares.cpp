/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1);

		for (int i = 0; i <= n; i++) {
			// e.g. 12 can be 1 + 1 + 1 ... + 1 -> 12
			//      13 can be 1 + 1 + 1 ... + 1 + 1 -> 13
			// the goal is finding the minimun value
			dp[i] = i;

			for (int j = 1; i >= j * j; j++)
				// e.g. 12 could be dp[11] + 1, dp[8] + 1 or dp[4] + 1
				//      13 could be dp[12] + 1, dp[9] + 1 or dp[4] + 1
				// the index is the remain number for perfect squares
				// => i - j ^ 2
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		return dp[n];
	}
};
// @lc code=end

