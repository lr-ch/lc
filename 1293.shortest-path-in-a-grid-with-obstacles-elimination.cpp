/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
	typedef pair<int, int> coord;	// (x, y)

	// check if c(x, y) is proceedable, and return remain k if possible, -1 if not possible
	int isProceedable(vector<vector<int>>& g, vector<vector<int>>& r, coord c, int k) {
		if (c.second < 0 || c.second >= g.size() ||			// out of boundary (y-direction)
			c.first < 0 || c.first >= g[0].size() ||		// out of boundary (x-direction)
			k < g[c.second][c.first] ||						// unable to remove obstacle in grid
			k <= r[c.second][c.first])						// this grid is visited
			return -1;
		return k - g[c.second][c.first];
	}

public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		int steps = 0;
		int m = grid.size(), n = grid[0].size();

		vector<vector<int>> remains(m, vector<int>(n, INT_MIN));
		queue<pair<coord, int>> q;		// <(x, y), remain k>

		q.push({ {0, 0}, k });	// start from <(0, 0), k>
		remains[0][0] = k;		// remain k at (0, 0)

		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [cc, rk] = q.front();
				q.pop();

				// reach the goal
				if (cc.first == n - 1 && cc.second == m - 1)
					return steps;

				// go right
				int right = isProceedable(grid, remains, {cc.first + 1, cc.second}, rk);
				if (right != -1) {
					q.push({ {cc.first + 1, cc.second}, right });
					remains[cc.second][cc.first + 1] = right;
				}

				// go down
				int down = isProceedable(grid, remains, {cc.first, cc.second + 1}, rk);
				if (down != -1) {
					q.push({ {cc.first, cc.second + 1}, down });
					remains[cc.second + 1][cc.first] = down;
				}

				// go left
				int left = isProceedable(grid, remains, {cc.first - 1, cc.second}, rk);
				if (left != -1) {
					q.push({ {cc.first - 1, cc.second}, left });
					remains[cc.second][cc.first - 1] = left;
				}

				// go up
				int up = isProceedable(grid, remains, {cc.first, cc.second - 1}, rk);
				if (up != -1) {
					q.push({ {cc.first, cc.second - 1}, up });
					remains[cc.second - 1][cc.first] = up;
				}
			}
			steps++;
		}
		return -1;
	}
};
// @lc code=end
