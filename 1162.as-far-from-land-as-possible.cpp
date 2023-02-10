/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int N = grid.size();
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (grid[i][j]) q.push({ i, j });

		if (q.size() == 0 /* no lands */ || q.size() == N * N /* no water */)
			return -1;

		int steps = 0;
		while (!q.empty()) {
			steps++;
			int qsize = q.size();

			while (qsize--) {
				auto [row, col] = q.front();
				q.pop();

				if (row + 1 < N && grid[row + 1][col] == 0) {
					grid[row + 1][col] = steps;
					q.push({ row + 1, col });
				}
				if (col + 1 < N && grid[row][col + 1] == 0) {
					grid[row][col + 1] = steps;
					q.push({ row, col + 1 });
				}
				if (row > 0 && grid[row - 1][col] == 0) {
					grid[row - 1][col] = steps;
					q.push({ row - 1, col });
				}
				if (col > 0 && grid[row][col - 1] == 0) {
					grid[row][col - 1] = steps;
					q.push({ row, col - 1 });
				}
			}
		}
		return steps - 1;
	}
};
// @lc code=end
