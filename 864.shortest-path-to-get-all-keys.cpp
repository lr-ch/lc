/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
	typedef bitset<6> hold_keys;	// 6 keys at most

	void find_start_count_keys(vector<string>& grid) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] == '@') {
					start_r = i;
					start_c = j;
				}

				if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
					total_keys++;
			}
		}
	}

	int M, N, start_r, start_c, total_keys = 0;
	vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
	int shortestPathAllKeys(vector<string>& grid) {
		M = grid.size(), N = grid[0].length();
		find_start_count_keys(grid);

		// 6 keys at most, 2 ^ 6 = 64
		vector<vector<vector<bool>>> visited(M, vector<vector<bool>>(N, vector<bool>(64, false)));
		queue<tuple<int, int, int, hold_keys>> q;	// (r, c, steps, hold keys)
		q.push({start_r, start_c, 0, 0});

		while (!q.empty()) {
			auto [r, c, steps, curr_keys] = q.front(); q.pop();

			if (r >= 0 && r < M && c >= 0 && c < N && grid[r][c] != '#' && !visited[r][c][curr_keys.to_ulong()]) {
				// skip if this grid is locked and we have no key
				if (isupper(grid[r][c]) && curr_keys[grid[r][c] - 'A'] == 0)
					continue;

				// pick up the key
				if (islower(grid[r][c])) curr_keys[grid[r][c] - 'a'] = 1;

				// if all keys collected
				if (curr_keys.count() == total_keys) return steps;

				// update the state of this grid
				visited[r][c][curr_keys.to_ulong()] = true;

				for (const auto& [nr, nc] : dirs)
					q.push({r + nr, c + nc, steps + 1, curr_keys});
			}
		}

		return -1;
	}
};
// @lc code=end
