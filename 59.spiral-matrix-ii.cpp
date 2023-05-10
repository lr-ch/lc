/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int	base_row = 0, limit_row = n - 1,
			base_col = 0, limit_col = n - 1,
			num = 1;
		vector<vector<int>> ans(n, vector<int>(n));

		while (num <= n * n) {
			if (base_row <= limit_row) {
				for (int i = base_col; i <= limit_col; i++)
					ans[base_row][i] = num++;
				base_row++;
			}

			if (base_col <= limit_col) {
				for (int i = base_row; i <= limit_row; i++)
					ans[i][limit_col] = num++;
				limit_col--;
			}

			if (base_row <= limit_row) {
				for (int i = limit_col; i >= base_col; i--)
					ans[limit_row][i] = num++;
				limit_row--;
			}

			if (base_col <= limit_col) {
				for (int i = limit_row; i >= base_row; i--)
					ans[i][base_col] = num++;
				base_col++;
			}
		}

		return ans;
	}
};
// @lc code=end
