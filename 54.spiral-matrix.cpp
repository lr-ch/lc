/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int depth = matrix.size(), width = matrix[0].size(),
			base_row = 0, limit_row = depth - 1,
			base_col = 0, limit_col = width - 1;
		vector<int> ans;

		while (ans.size() < depth * width) {
			if (base_row <= limit_row) {
				for (int i = base_col; i <= limit_col; i++)
					ans.push_back(matrix[base_row][i]);
				base_row++;
			}

			if (base_col <= limit_col) {
				for (int i = base_row; i <= limit_row; i++)
					ans.push_back(matrix[i][limit_col]);
				limit_col--;
			}

			if (base_row <= limit_row) {
				for (int i = limit_col; i >= base_col; i--)
					ans.push_back(matrix[limit_row][i]);
				limit_row--;
			}

			if (base_col <= limit_col) {
				for (int i = limit_row; i >= base_row; i--)
					ans.push_back(matrix[i][base_col]);
				base_col++;
			}
		}

		return ans;
	}
};
// @lc code=end
