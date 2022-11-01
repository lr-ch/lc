/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
	int dfs(int row, int col, vector<vector<int>>& g) {
		// reach bottom
		if (row == g.size()) return col;

		int nextCol = col + g[row][col];
		if (nextCol < 0 ||						// out of boundary
			nextCol >= g[0].size() ||			// out of boundary
			g[row][col] != g[row][nextCol])		// stuck
			return -1;

		return dfs(row + 1, nextCol, g);
	}

	array<int, 100> res;
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		fill(res.begin(), res.end(), 0);

		// iterate each column
		for (int i = 0; i < grid[0].size(); i++)
			res[i] = dfs(0, i, grid);

		return vector<int>(res.begin(), res.begin() + grid[0].size());
	}
};
// @lc code=end

