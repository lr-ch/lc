/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
	void printSudoku(vector<vector<char>>& b) {
		int i, j;
		for (i = 0; i < 9; i++) {
			cout << "[";
			for (j = 0; j < 8; j++) {
				cout << b[i][j] << ",";
			}
			cout << b[i][j] << "]" << endl;
		}
        cout << endl;
	}

	bool isValid(vector<vector<char>>& b, int r, int c, char n) {
		for (int i = 0; i < 9; i++) {
			// check other cols
			if (b[r][i] == n) return false;
			// check other rows
			if (b[i][c] == n) return false;
			// check other numbers in the same 3x3 blocks
			if (b[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == n)
				return false;
		}
		return true;
	}

	bool bt(vector<vector<char>>& b) {
	//	printSudoku(b);
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				if (b[row][col] == '.') {
					for (char c = '1'; c <= '9'; c++) {
						if (isValid(b, row, col, c)) {
							b[row][col] = c;
							if (bt(b))
								return true;
							b[row][col] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

public:
	void solveSudoku(vector<vector<char>>& board) {
		bt(board);
	}
};
// @lc code=end

