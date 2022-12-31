/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
	void traverse(vector<vector<int>>& g, vector<vector<int>>& v, int r, int c, int count) {
		// check boundary
		if (r < 0 || r >= R || c < 0 || c >= C) return;

		// reach end and every empty squares are counted
		if (g[r][c] == 2 && count == empties) {
			res++;
			return;
		}

		// if the grid is visited
		// start, end, obstacles are already marked as visited
		if (v[r][c] == 1) return;

		v[r][c] = 1;
		traverse(g, v, r + 1, c, count + 1);
		traverse(g, v, r, c + 1, count + 1);
		traverse(g, v, r - 1, c, count + 1);
		traverse(g, v, r, c - 1, count + 1);
		v[r][c] = 0;
	}

	int res, empties, R, C;
	pair<int, int> start, end;
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		res = 0;
		empties = 0;
		R = grid.size(), C = grid[0].size();

		vector<vector<int>> visited(R, vector<int>(C, 0));

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				switch (grid[i][j]) {
					case 0 :
						empties++;
						break;
					case 1 :
						start.first = i;
						start.second = j;
						visited[i][j] = 1;
						break;
					case 2 :
						end.first = i;
						end.second = j;
						visited[i][j] = 1;
						break;
					case -1 :
						visited[i][j] = 1;
						break;
				}
			}
		}

		// don't forget the start grid could be anywhere in the grid
		// not just the most upper-left
		traverse(grid, visited, start.first + 1, start.second, 0);
		traverse(grid, visited, start.first, start.second + 1, 0);
		traverse(grid, visited, start.first - 1, start.second, 0);
		traverse(grid, visited, start.first, start.second - 1, 0);

		return res;
	}
};
// @lc code=end

