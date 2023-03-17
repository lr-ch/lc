/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
	struct TrieNode {
		array<TrieNode *, 26> next;
		bool terminated;

		TrieNode() {
			for (auto& it : next) it = nullptr;
			terminated = false;
		}
		~TrieNode() {
			for (auto& it : next) if (it) delete it;
		}
	};

	TrieNode *root;
public:
	Trie() {
		root = new TrieNode;
	}

	void insert(string word) {
		TrieNode *tmp = root;
		for (const auto& ch : word) {
			int i = ch - 'a';
			if (!tmp->next[i])
				tmp->next[i] = new TrieNode;
			tmp = tmp->next[i];
		}
		tmp->terminated = true;
	}

	bool search(string word) {
		TrieNode *tmp = root;
		for (const auto& ch : word) {
			int i = ch - 'a';
			if (!tmp->next[i])
				return false;
			tmp = tmp->next[i];
		}
		return tmp->terminated;
	}

	bool startsWith(string prefix) {
		TrieNode *tmp = root;
		for (const auto& ch : prefix) {
			int i = ch - 'a';
			if (!tmp->next[i])
				return false;
			tmp = tmp->next[i];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
