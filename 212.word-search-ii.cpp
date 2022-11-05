/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
	struct TrieNode {
		vector<TrieNode *> nodes;
		string *word;
		TrieNode() : nodes(26), word(nullptr) {}
		~TrieNode() { for (auto node : nodes) delete node; }
	};

	void bt(vector<vector<char>>& b, int x, int y, TrieNode* node) {
		if (x < 0 || x >= colSize || y < 0 || y >= rowSize ||	// out of boundary
			b[y][x] == '*')										// visited
			return;

		char curr = b[y][x];
		TrieNode* next = node->nodes[curr - 'a'];

		// give up if next node is not existed
		if (!next) return;

		if (next->word) {
			res.push_back(*next->word);
			next->word = nullptr;
		}

		b[y][x] = '*';
		bt(b, x + 1, y, next);
		bt(b, x, y + 1, next);
		bt(b, x - 1, y, next);
		bt(b, x, y - 1, next);
		b[y][x] = curr;
	}

	int rowSize, colSize;
	vector<string> res;
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		TrieNode root;

		// construct Trie for all words
		for (auto& word : words) {
			TrieNode *curr = &root;
			for (char c : word) {
				auto& next = curr->nodes[c - 'a'];
				if (!next) next  = new TrieNode();
				curr = next;
			}
			curr->word = &word;
		}

		rowSize = board.size();
		colSize = board[0].size();

		// traverse the board
		for (int x = 0; x < colSize; x++)
			for (int y = 0; y < rowSize; y++)
				bt(board, x, y, &root);

		return res;
	}
};
// @lc code=end
