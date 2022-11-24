/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
	bool bt(vector<vector<char>>& b, string w, int index, pair<int, int> pos) {
		// check boundary
		if (pos.first < 0 || pos.first >= b.size() ||
			pos.second < 0 || pos.second >= b[0].size()) return false;

		char *curChar = &b[pos.first][pos.second];

		// check visited
		if (*curChar == 0) return false;

		bool res = false;
		// compare to word[i]
		if (*curChar == w[index]) {
			// last character?
			if (index == w.length() - 1) return true;

			// mark as visited
			*curChar = 0;

			// continue searching
			res = bt(b, w, index + 1, { pos.first + 1, pos.second }) ||
				  bt(b, w, index + 1, { pos.first, pos.second + 1 }) ||
				  bt(b, w, index + 1, { pos.first - 1, pos.second }) ||
				  bt(b, w, index + 1, { pos.first, pos.second - 1 });

			// undo visited mark for next round search
			*curChar = w[index];
		}
		return res;
	}

public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (bt(board, word, 0, { i, j }))
					return true;
		return false;
	}
};
// @lc code=end
