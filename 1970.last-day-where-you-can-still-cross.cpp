/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
class Solution {
	struct UnionFind {
		vector<int> boss;

		UnionFind(int k) {
			boss.resize(k);
			iota(boss.begin(), boss.end(), 0);
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
			if (bossX != bossY)
				bossX > bossY ? boss[bossY] = bossX : boss[bossX] = bossY;
		}
	};

	vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
	int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
		UnionFind uf(row * col + 2);	// add two more nodes to unite top and bottom
		// Unite top row to virtual node #top
		for (int tc = 0; tc < col; tc++)
			uf.unite(tc, row * col);
		// Unite bottom row to virtual node #bottom
		for (int bc = 0; bc < col; bc++)
			uf.unite((row - 1) * col + bc, row * col + 1);

		// create water world
		vector<vector<int>> world(row, vector<int>(col, 0));
		for (const auto& cell : cells)
			world[cell[0] - 1][cell[1] - 1] = 1;

		// unite each cell
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (world[i][j] == 1) continue;

				for (const auto& [r, c] : dirs)
					if (i + r >= 0 && i + r < row && j + c >= 0 && j + c < col && world[i + r][j + c] == 0)
						uf.unite(i * col + j, (i + r) * col + (j + c));
			}
		}

		// restore world and check top and bottom are united
		for (int i = cells.size() - 1; i >= 0; i--) {
			int cur_row = cells[i][0] - 1, cur_col = cells[i][1] - 1;
			world[cur_row][cur_col] = 0;

			for (const auto& [r, c] : dirs) {
				if (cur_row + r < 0 || cur_row + r >= row || cur_col + c < 0 || cur_col + c >= col)
					continue;

				if (world[cur_row + r][cur_col + c] == 0)
					uf.unite(cur_row * col + cur_col, (cur_row + r) * col + (cur_col + c));
			}

			if (uf.find(row * col) == uf.find(row * col + 1))
				return i;
		}

		return 0;
	}
};
// @lc code=end
