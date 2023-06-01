/*
 * @lc app=leetcode id=2435 lang=cpp
 *
 * [2435] Paths in Matrix Whose Sum Is Divisible by K
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int numberOfPaths(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();

		/*
		 *  dp[i][j][s] = path sum from (0, 0) to (i, j) = s
		 *  dp[i][j][s + grid[i][j]] = dp[i - 1][j][s] + dp[i][j - 1][s]
		 */
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
		dp[0][0][grid[0][0] % k] = 1;

		/*
		 *  (sum + sum') % k = (sum % k + sum') % k
		 *  => (s + grid[i][j]) % k
		 *  => (s % k + grid[i][j]) % k
		 */
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) continue;		// skip base case
				for (int r = 0; r < k; r++) {
					int sum_i = (i == 0 ? 0 : dp[i - 1][j][r]),
						sum_j = (j == 0 ? 0 : dp[i][j - 1][r]);
					dp[i][j][(grid[i][j] + r) % k] = (sum_i + sum_j) % MOD;
				}
			}
		}

		return dp[m - 1][n - 1][0];
	}
};
// @lc code=end
