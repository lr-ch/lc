/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {
		multiset<vector<int>> rows(grid.begin(), grid.end());

		vector<int> tmp;
		int ans = 0;
		for (int c = 0; c < grid[0].size(); c++) {
			for (int r = 0; r < grid.size(); r++)
				tmp.push_back(grid[r][c]);

			ans += rows.count(tmp);
			tmp.clear();
		}

		return ans;
	}
};
// @lc code=end
