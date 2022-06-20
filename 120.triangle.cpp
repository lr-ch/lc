/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
	int traverse (
			int row,
			int col,
			vector<vector<int>>& t,
			vector<vector<int>>& m)
	{
		// boudary condition
		// don't need to check col, because it is constrained by row
		if (row == t.size() - 1)
			return t[row][col];

		if (m[row][col] != INT_MAX)
			return m[row][col];

		int left = t[row][col] + traverse(row + 1, col, t, m);
		int right = t[row][col] + traverse(row + 1, col + 1, t, m);
		return m[row][col] = min(left, right);
	}

public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int depth = triangle.size();
		vector<vector<int>>	memo(depth, vector<int>(depth, INT_MAX));
		return traverse(0, 0, triangle, memo);
	}
};
// @lc code=end

