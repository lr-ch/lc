/*
 * @lc app=leetcode id=2482 lang=cpp
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();
		unordered_map<int, int> onesRow, onesCol;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				onesRow[i] += grid[i][j];
				onesCol[j] += grid[i][j];
			}

		vector<vector<int>> diff(R, vector<int>(C, 0));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - R - C;

		return diff;
	}
};
// @lc code=end
