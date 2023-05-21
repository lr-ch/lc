/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
	void dfs(int r, int c, vector<vector<int>>& g) {
		if (r < 0 || r >= N || c < 0 || c >= N || 0 == g[r][c] || 2 == g[r][c])
			return;

		// mark as first island
		g[r][c] = 2;
		q.push({ r, c });
		for (const auto& [v, h] : dirs)
			dfs(r + v, c + h, g);
	}

	queue<pair<int, int>> q;	// coords of first island
	vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	int N;
public:
	int shortestBridge(vector<vector<int>>& grid) {
		N = grid.size();

		// find out all grids of first island
		bool found = false;
		for (int i = 0; i < N && !found; i++)
			for (int j = 0; j < N && !found; j++)
				if (grid[i][j] == 1) {
					dfs(i, j, grid);
					found = true;
				}

		// expand the first island to reach second island
		int steps = 0;
		while (!q.empty()) {
			int qsize = q.size();

			while (qsize--) {
				auto [row, col] = q.front(); q.pop();

				for (const auto& [v, h] : dirs) {
					int r = row + v, c = col + h;
					if (r < 0 || r >= N || c < 0 || c >= N || 2 == grid[r][c])
						continue;

					if (1 == grid[r][c]) return steps;

					grid[r][c] = 2;
					q.push({ r, c });
				}
			}
			steps++;
		}
		return -1;	// should not come here
	}
};
// @lc code=end
