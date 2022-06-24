/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
	vector<vector<string>> ans;

	bool isValidCol(vector<string>& b, int r, int c) {
		for (int i = r; i >= 0; i--)
			if (b[i][c] == 'Q')
				return false;
		return true;
	}

	bool isValidDiag(vector<string>& b, int r, int c) {
		// to upper left
		for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
			if (b[i][j] == 'Q')
				return false;
		// to upper right
		for (int i = r - 1, j = c + 1; i >= 0 && j < b[r].length(); i--, j++)
			if (b[i][j] == 'Q')
				return false;

		return true;
	}

	void backtrack(vector<string>& board, int row) {
		// complete a board
		if (row == board.size()) {
			ans.push_back(board);
			return;
		}

		for (int col = 0; col < board[row].length(); col++) {
			// no queen on the same col on other row?
			if (!isValidCol(board, row, col)) continue;
			// no queen on the diagonal?
			if (!isValidDiag(board, row, col)) continue;

			// ok, the col is fine
			board[row][col] = 'Q';
			backtrack(board, row + 1);
			// undo the selection for next iteration
			board[row][col] = '.';
		}
	}

public:
	int totalNQueens(int n) {
		// initialize
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0);
		return ans.size();
	}
};
// @lc code=end
