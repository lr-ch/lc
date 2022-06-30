/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
	bool isAllRowsValid(vector<vector<char>>& board) {
		array<bool, 10> used;
		for (int i = 0; i < board.size(); i++) {
			fill(used.begin(), used.end(), false);
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == '.')
					continue;
				int digit = board[i][j] - '0';
				if (used[digit] == false)
					used[digit] = true;
				else
					return false;
			}
		}
		return true;
	}

	bool isAllColsValid(vector<vector<char>>& board) {
		array<bool, 10> used;
		for (int i = 0; i < board.size(); i++) {
			fill(used.begin(), used.end(), false);
			for (int j = 0; j < board[i].size(); j++) {
				if (board[j][i] == '.')
					continue;
				int digit = board[j][i] - '0';
				if (used[digit] == false)
					used[digit] = true;
				else
					return false;
			}
		}
		return true;
	}

	bool isSubBlockValid(vector<vector<char>>& board, int r, int c) {
		array<bool, 10> used;
		fill(used.begin(), used.end(), false);
		for (int i = r; i < r + 3; i++) {
			for (int j = c; j < c + 3; j++) {
				if (board[i][j] == '.')
					continue;
				int digit = board[i][j] - '0';
				if (used[digit] == false)
					used[digit] = true;
				else
					return false;
			}
		}
		return true;
	}

	bool isAllBlocksValid(vector<vector<char>>& board) {
		return isSubBlockValid(board, 0, 0) && isSubBlockValid(board, 0, 3) && isSubBlockValid(board, 0, 6)
			&& isSubBlockValid(board, 3, 0) && isSubBlockValid(board, 3, 3) && isSubBlockValid(board, 3, 6)
			&& isSubBlockValid(board, 6, 0) && isSubBlockValid(board, 6, 3) && isSubBlockValid(board, 6, 6);
	}

public:
	bool isValidSudoku(vector<vector<char>>& board) {
		return isAllRowsValid(board) && isAllColsValid(board)
				&& isAllBlocksValid(board);
	}
};
// @lc code=end

