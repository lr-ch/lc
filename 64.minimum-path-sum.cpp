/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (i == 0 && j > 0) grid[0][j] += grid[0][j - 1];
				else if (i > 0 && j == 0) grid[i][0] += grid[i - 1][0];
				else if (i > 0 && j > 0) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

		return grid[grid.size() - 1][grid[0].size() - 1];
	}
};
// @lc code=end
