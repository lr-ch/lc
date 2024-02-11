/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
	/*
	 * dfs[current row][column of RobotA][column of RobotB] -> the maximun cherries
	 */
	int dfs(vector<vector<int>>& g, int r, int ca, int cb) {
		// boundary check
		if (ca < 0 || ca >= g[0].size() || cb < 0 || cb >= g[0].size() || r == g.size())
			return 0;

		if (memo[r][ca][cb] != INT_MIN) return memo[r][ca][cb];

		for (int nca = ca - 1; nca <= ca + 1; nca++)
			for (int ncb = cb - 1; ncb <= cb + 1; ncb++)
				if (nca < ncb)
					memo[r][ca][cb] = max(memo[r][ca][cb], dfs(g, r + 1, nca, ncb));

		return memo[r][ca][cb] += g[r][ca] + g[r][cb];
	}

	vector<vector<vector<int>>> memo;
public:
	int cherryPickup(vector<vector<int>>& grid) {
		memo.resize(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), INT_MIN)));
		return dfs(grid, 0, 0, grid[0].size() - 1);
	}
};
// @lc code=end
