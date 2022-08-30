/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class RotateInPlace {
public:
	void rotate(vector<vector<int>>& matrix) {
		int col = matrix[0].size(), n = col - 1;
		for (int i = 0; i < col / 2 + col % 2; i++)
			for (int j = 0; j < col / 2; j++) {
				int tmp = matrix[n - j][i];
				matrix[n - j][  i  ] = matrix[n - i][n - j];
				matrix[n - i][n - j] = matrix[  j  ][n - i];
				matrix[  j  ][n - i] = matrix[  i  ][  j  ];
				matrix[  i  ][  j  ] = tmp;
			}
	}
};

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		for (int i = 0; i < row; i++)
			for (int j = i + 1; j < row; j++)
				swap(matrix[i][j], matrix[j][i]);

		for (int i = 0; i < row; i++)
			reverse(matrix[i].begin(), matrix[i].end());
	}
};
// @lc code=end

