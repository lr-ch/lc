/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
	int dp(int row, int col, vector<vector<int>>& m) {
		if (row == 0 && col == 0) return 1;
		if (row < 0 || col < 0) return 0;
		if (m[row][col] != -1) return m[row][col];

		// total moves = vertical moves + horizontal moves
		m[row][col] = dp(row - 1, col, m) + dp(row, col - 1, m);
		return m[row][col];
	}

public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> memo(m, vector<int>(n, -1));
		return dp(m - 1, n - 1, memo);
	}
};
// @lc code=end

