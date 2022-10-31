/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		for (int row = 0; row < m; row++)
			for (int col = 0; col < n; col++)
				if (row > 0 && col > 0 &&
					matrix[row][col] != matrix[row - 1][col - 1])
					return false;
		return true;
	}
};
// @lc code=end
