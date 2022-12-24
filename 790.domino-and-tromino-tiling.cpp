/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int numTilings(int n) {
		array<array<long, 3>, 1001> dp;

		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[1][2] = 1;
		dp[2][0] = 2;
		dp[2][1] = 1;
		dp[2][2] = 1;

		for (int i = 3; i <= n; i++) {
			/*
			 *  [i-1][0]   +   [i-2][0]   +   [i-1][1]   +   [i-1][2]
			 *  O ... O X     O ... O XX     O ... OO X     O ... O XX
			 *  O ... O X     O ... O YY     O ... O XX     O ... OO X
			 */
			dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;

			/*
			 *   [i-2][0]   +   [i-1][2]
			 *  O ... O XX     O ... XX
			 *  O ... O X      O ... O
			 */
			dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % MOD;

			/*
			 *   [i-2][0]   +   [i-1][1]
			 *  O ... O X      O ... O
			 *  O ... O XX     O ... XX
			 */
			dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % MOD;
		}

		return dp[n][0] % MOD;
	}
};
// @lc code=end
