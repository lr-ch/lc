/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		vector<vector<double>> dp(100, vector<double>(100));	// dp[r][c] := liquid in row r, col c
		dp[0][0] = poured;
		for (int r = 0; r < query_row; r++)
			for (int c = 0; c <= r; c++)
				if (dp[r][c] > 1) {
					dp[r + 1][  c  ] += (dp[r][c] - 1.0) / 2.0;
					dp[r + 1][c + 1] += (dp[r][c] - 1.0) / 2.0;
				}
		return min(1.0, dp[query_row][query_glass]);
	}
};
// @lc code=end
