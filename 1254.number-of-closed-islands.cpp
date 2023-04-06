/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
	/*
	 * Copy from 200. Number of Islands
	 */
	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
			return 0;
		if (grid[i][j] == 1) return 0;
		grid[i][j] = 1;
		dfs(grid, i + 1, j);
		dfs(grid, i, j + 1);
		dfs(grid, i - 1, j);
		dfs(grid, i, j - 1);
		return 1;
	}

public:
	int closedIsland(vector<vector<int>>& grid) {
		// remove island adjencent to map edge,
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
