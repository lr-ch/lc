/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
	inline bool isValidCoord(int r, int c, vector<vector<int>>& g) {
		return r >= 0 && r < n && c >= 0 && c < n && g[r][c] == 0;
	}

	int n;
	const vector<pair<int, int>> dirs = { {1,  0}, { 0,  1}, {-1,  0}, { 0, -1},
										  {1,  1}, { 1, -1}, {-1, -1}, {-1,  1} };
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		n = grid.size();

		queue<pair<int, int>> q;
		if (grid[0][0] == 0) {
			grid[0][0] = 1;
			q.push({ 0, 0 });
		}

		while (!q.empty()) {
			auto [row, col] = q.front(); q.pop();

			if (row == n - 1 && col == n - 1) return grid[row][col];

			for (const auto& [r, c] : dirs) {
				if (isValidCoord(row + r, col + c, grid)) {
					grid[row + r][col + c] = grid[row][col] + 1;
					q.push({ row + r, col + c });
				}
			}
		}

		return -1;
	}
};
// @lc code=end
