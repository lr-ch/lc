/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
	int dp(int y, int x, vector<vector<int>>& g, vector<vector<int>>& m) {
		if (y >= g.size() || x >= g[0].size() || g[y][x] == 1) return 0;
		if (x == 0 && y == 0) return 1;
		if (m[y][x] != -1) return m[y][x];

		m[y][x] = dp(y - 1, x, g, m) + dp(y, x - 1, g, m);
		return m[y][x];
	}

public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> memo(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
		return dp(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, obstacleGrid, memo);
	}
};
// @lc code=end
