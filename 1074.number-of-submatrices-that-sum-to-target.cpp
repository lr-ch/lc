/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution {
	void printV(vector<vector<int>>& m) {
		for (auto i : m) {
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}
		cout << endl;
	}

	void printA(int a[101][101], int m, int n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int row = matrix.size(), col = matrix[0].size(), count=0;
		int temp[101][101];

	//	printV(matrix);

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				temp[i + 1][j] = temp[i][j] + matrix[i][j];
	//	printA(temp, row + 1, col);

		for (int i = 0; i < row; i++) {
			for (int j = i + 1; j <= row; j++) {
				for (int k = 0; k < col; k++) {
					int sum=0;
					for (int l = k; l < col; l++) {
						sum += temp[j][l] - temp[i][l];
						if (sum == target) {
							count++;
						}
					}
				}
			}
		}
		return count;
	}
};
// @lc code=end

