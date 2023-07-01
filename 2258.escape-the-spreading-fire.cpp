/*
 * @lc app=leetcode id=2258 lang=cpp
 *
 * [2258] Escape the Spreading Fire
 */

// @lc code=start
class Solution {
	void bfs(vector<vector<int>>& grid, vector<vector<int>>& target, queue<pair<int, int>>& q, bool type) {
		int time = 1;
		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [cr, cc] = q.front(); q.pop();
				for (const auto& [dr, dc] : dirs) {
					int r = cr + dr, c = cc + dc;
					if (r < 0 || r >= row || c < 0 || c >= col) continue;
					if (grid[r][c] == 2 || target[r][c] != INT_MAX) continue;
					if (type && grid[r][c] == 1) continue;	// person cannot reach fire grid
					target[r][c] = time;
					q.push({r, c});
				}
			}
			time++;
		}
	}

	int row, col;
	vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
	int maximumMinutes(vector<vector<int>>& grid) {
		row = grid.size(), col = grid[0].size();

		// init person time matrix
		queue<pair<int, int>> q;
		q.push({0, 0});
		vector<vector<int>> person(row, vector<int>(col, INT_MAX));	// the minimun time person reaches grid[r][c]
		bfs(grid, person, q, true);

		// init fire time matrix
		vector<vector<int>> fire(row, vector<int>(col, INT_MAX));	// the minimun time fire starts at (r, c)
		// set fire
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (grid[i][j] == 1) q.push({i, j});
		bfs(grid, fire, q, false);

		// check boudary conditions
		if (person[row - 1][col - 1] == INT_MAX)
			return -1;		// person never gets safehouse
		if (person[row - 1][col - 1] > fire[row - 1][col - 1])
			return -1;		// person always slow than fire
		if (fire[row - 1][col - 1] == INT_MAX)
			return 1e9;		// fire never gets safehouse

		vector<vector<bool>> visited(row, vector<bool>(col, false));
		priority_queue<tuple<int, int, int>> pq;				// (t, r, c) => the maximun time(t) person should reach grid[r][c]
		pq.push({fire[row - 1][col - 1], row - 1, col - 1});	// the maximun time person should reach safehouse is fire[row - 1][col -1]

		// from safehouse backward to start point, use Dijkstra's algorithm
		while (!pq.empty()) {
			auto [t, r, c] = pq.top(); pq.pop();

			if (visited[r][c]) continue;
			visited[r][c] = true;
			if (r == 0 && c == 0) return t >= 0 ? t : -1;
			for (const auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc;
				if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] != 2 && !visited[nr][nc])
					// person can only reach to (nr, nc) before the time person[r][c] or fire[nr][nc]
					pq.push({min(t - 1, fire[nr][nc] - 1), nr, nc});
			}
		}
		return -1;
	}
};
// @lc code=end
