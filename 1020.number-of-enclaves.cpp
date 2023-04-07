/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
			return 0;
		if (grid[i][j] == 0) return 0;
		grid[i][j] = 0;

		int total = 1;
		total += dfs(grid, i + 1, j);
		total += dfs(grid, i, j + 1);
		total += dfs(grid, i - 1, j);
		total += dfs(grid, i, j - 1);
		return total;
	}

public:
	int numEnclaves(vector<vector<int>>& grid) {
		// remove land cells adjancent to boundary,
		// first and last column
		for (int m = 0; m < grid.size(); m++) {
			dfs(grid, m, 0);
			dfs(grid, m, grid[0].size() - 1);
		}
		// first and last row
		for (int n = 0; n < grid[0].size(); n++) {
			dfs(grid, 0, n);
			dfs(grid, grid.size() - 1, n);
		}

		int ans = 0;
		for (int i = 1; i < grid.size(); i++)
			for (int j = 1; j < grid[0].size(); j++)
				ans += dfs(grid, i, j);

		return ans;
	}
};
// @lc code=end
