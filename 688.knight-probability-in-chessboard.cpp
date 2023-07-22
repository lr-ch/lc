/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
	double dfs(int n, int k, int r, int c) {
		if (r < 0 || r >= n || c < 0 || c >= n) return 0;
		if (k == 0) return 1;

		if (dp[r][c][k] != -1.0) return dp[r][c][k];

		double p = 0;
		for (const auto& [row, col] : dirs)
			p += dfs(n, k - 1, r + row, c + col) / 8.0;

		return dp[r][c][k] = p;
	}

	vector<vector<vector<double>>> dp;
	vector<pair<int, int>> dirs = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
									{2, 1}, {2, -1}, {-2, 1}, {-2, -1} };
public:
	double knightProbability(int n, int k, int row, int column) {
		dp.resize(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
		return dfs(n, k, row, column);
	}
};
// @lc code=end
