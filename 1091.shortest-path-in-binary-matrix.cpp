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

	array<pair<int, int>, 8> dirs = { pair<int, int>(1,  0), { 0,  1}, {-1,  0}, { 0, -1},
													{1,  1}, { 1, -1}, {-1, -1}, {-1,  1} };
	int n;
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		n = grid.size();

		queue<array<int, 3>> q;
		if (grid[0][0] == 0) {
			grid[0][0] = 2;		// marked as visited
			q.push({ 0, 0, 1 });
		}

		while (!q.empty()) {
			auto pos = q.front(); q.pop();
			int row = pos[0], col = pos[1], steps = pos[2];

			if (row == n - 1 && col == n - 1) return steps;

			for (const auto& [r, c] : dirs) {
				if (isValidCoord(row + r, col + c, grid)) {
					grid[row + r][col + c] = 2;		// marked as visited
					q.push({ row + r, col + c, steps + 1 });
				}
			}
		}

		return -1;
	}
};
// @lc code=end
