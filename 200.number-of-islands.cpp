/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
	int sink(vector<vector<char>>& sea, int latitude, int longitude) {
		if (latitude < 0 || longitude < 0 || latitude >= sea.size() || longitude >= sea[0].size())
			return 0;
		if (sea[latitude][longitude] == '0')
			return 0;

		sea[latitude][longitude] = '0';
		sink(sea, latitude + 1, longitude);
		sink(sea, latitude, longitude + 1);
		sink(sea, latitude - 1, longitude);
		sink(sea, latitude, longitude - 1);
		return 1;
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				ans += sink(grid, i, j);
		return ans;
	}
};
// @lc code=end
