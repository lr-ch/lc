/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
	int area(vector<vector<int>>& g, vector<vector<bool>>& m, int row, int col) {
		if (row < 0 || row >= g.size() || col < 0 || col >= g[0].size() ||
			m[row][col] || g[row][col] == 0) return 0;

		m[row][col] = true;

		// g[row][col] is 1, so plus 1
		return (1 +
				area(g, m, row + 1, col) +	// go down
				area(g, m, row - 1, col) +	// go up
				area(g, m, row, col + 1) +	// go right
				area(g, m, row, col - 1));	// go left
	}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<bool>> mark(grid.size(), vector<bool>(grid[0].size(), false));

		int ans;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				ans = max(ans, area(grid, mark, i, j));

		return ans;
    }
};
// @lc code=end

