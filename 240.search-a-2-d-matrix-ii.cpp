/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size(), cols = matrix[0].size();

		// start from bottom-left
		int i = rows - 1, j = 0;
		while (i >= 0 && j < cols) {
			if (matrix[i][j] < target)
				j++;
			else if (matrix[i][j] > target)
				i--;
			else
				return true;
		}
		return false;
	}
};
// @lc code=end

