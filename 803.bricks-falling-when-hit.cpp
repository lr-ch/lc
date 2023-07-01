/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
class Solution {
	struct UnionFind {
		vector<int> boss;
		vector<int> groups;

		UnionFind(int k) {
			boss.resize(k);
			iota(boss.begin(), boss.end(), 0);
			groups.resize(k, 1);
		}

		int find(int x) {
			while (boss[x] != x) {
				boss[x] = boss[boss[x]];
				x = boss[x];
			}
			return boss[x];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				if (bossX < bossY) {
					boss[bossY] = bossX;
					groups[bossX] += groups[bossY];
				} else {
					boss[bossX] = bossY;
					groups[bossY] += groups[bossX];
				}
			}
		}
	};

	vector<pair<int, int>> dirs = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};
public:
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		vector<vector<int>> backup = grid;
		int row = grid.size(), col = grid[0].size();
		UnionFind uf(row * col);

		// apply all hits to get final result
		for (const auto& hit : hits)
			grid[hit[0]][hit[1]] = 0;

		// unite each brick
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 0) continue;

				for (const auto& [r, c] : dirs)
					if (i + r >= 0 && i + r < row && j + c >= 0 && j + c < col && grid[i + r][j + c] == 1)
						uf.unite(i * col + j, (i + r) * col + (j + c));
			}
		}

		// reverse time
		vector<int> res(hits.size(), 0);
		for (int i = hits.size() - 1; i >= 0; i--) {
			int hr = hits[i][0], hc = hits[i][1];

			// if the brick is originally empty, no fall and no restore
			if (backup[hr][hc] == 0) {
				res[i] = 0;
				continue;
			}

			// now restore the brick and check connectiveness
			grid[hr][hc] = 1;
			int isConnectTop = false;
			int count = 0;
			for (const auto& [r, c] : dirs) {
				int nr = hr + r, nc = hc + c;
				if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == 0)
					continue;

				int bossHitGrid = uf.find(hr * col + hc);
				int bossAdjGrid = uf.find(nr * col + nc);

				// skip if they are already connected
				if (bossHitGrid == bossAdjGrid) continue;

				if (bossHitGrid < col || bossAdjGrid < col) isConnectTop = true;

				// if the grid is not connected to top row
				if (bossAdjGrid >= col)
					count += uf.groups[bossAdjGrid];

				// connect hit grid and its adj grids
				uf.unite(nr * col + nc, hr * col + hc);
			}
			res[i] = isConnectTop ? count : 0;
		}
		return res;
	}
};
// @lc code=end
