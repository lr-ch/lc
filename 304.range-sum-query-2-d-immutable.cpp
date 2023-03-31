/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
	int R, C;
	vector<vector<int>> vec;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		R = matrix.size();
		C = matrix[0].size();

		vec.resize(R + 1, vector<int>(C + 1, 0));

		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				vec[r + 1][c + 1] = vec[r + 1][c] + vec[r][c + 1] + matrix[r][c] - vec[r][c];
	}

	inline int sumRegion(int row1, int col1, int row2, int col2) {
		return vec[row2 + 1][col2 + 1] - vec[row2 + 1][col1] - vec[row1][col2 + 1] + vec[row1][col1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
