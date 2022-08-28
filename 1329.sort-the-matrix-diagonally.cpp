/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		vector<int> tmp;

		// for each row
		for (int row = 0; row < m; row++) {
			tmp.clear();
			for (int r = row, c = 0; r < m && c < n; r++, c++)
				tmp.push_back(mat[r][c]);

			sort(tmp.begin(), tmp.end());
			auto iter = tmp.begin();

			for (int r = row, c = 0; r < m && c < n; r++, c++, iter++)
				mat[r][c] = *iter;
		}

		// for each col
		for (int col = 1; col < n; col++) {
			tmp.clear();
			for (int r = 0, c = col; r < m && c < n; r++, c++)
				tmp.push_back(mat[r][c]);

			sort(tmp.begin(), tmp.end());
			auto iter = tmp.begin();

			for (int r = 0, c = col; r < m && c < n; r++, c++, iter++)
				mat[r][c] = *iter;
		}
		return mat;
	}
};
// @lc code=end
