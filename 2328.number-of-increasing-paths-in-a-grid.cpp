/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 */

// @lc code=start
class Solution {
	int dfs(const vector<vector<int>>& g, int row, int col) {
		if (paths[row][col]) return paths[row][col];

		paths[row][col] = 1;
		for (const auto& [r, c] : dirs)
			if (row + r >= 0 && row + r < M &&
				col + c >= 0 && col + c < N &&
				g[row + r][col + c] > g[row][col])
				paths[row][col] += (dfs(g, row + r, col + c) % MOD);

		return paths[row][col] % MOD;
	}

	int M, N;
	vector<vector<int>> paths;
	const int MOD = 1e9 + 7;
	const vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
public:
	int countPaths(vector<vector<int>>& grid) {
		M = grid.size(), N = grid[0].size();
		paths.resize(M, vector<int>(N, 0));

		long res = 0;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				res += (dfs(grid, i, j) % MOD);

		return res % MOD;
	}
};
// @lc code=end
