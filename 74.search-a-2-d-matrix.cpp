/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int R = matrix.size(), C = matrix[0].size();
		int left = 0, right = R * C - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2,
				midVal = matrix[mid / C][mid % C];

			if (midVal == target) return true;
			else if (midVal < target) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
};
// @lc code=end
