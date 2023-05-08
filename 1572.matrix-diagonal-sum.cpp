/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat) {
		int ans = 0, m = mat.size();
		for (int i = 0; i < m; i++)
			ans += mat[i][i] + mat[i][m - 1 - i];
		if (m % 2) ans -= mat[m / 2][m / 2];
		return ans;
	}
};
// @lc code=end
