/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:
	array<Trie*, 26> next;
	bool terminated;

	Trie() {
		for (int i = 0; i < 26; i++) this->next[i] = nullptr;
		this->terminated = false;
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (this->next[i]) delete this->next[i];
		this->terminated = false;
	}

	void insert(string word) {
		Trie *node = this;
		for (const char ch : word) {
			if (!node->next[ch - 'a'])
				node->next[ch - 'a'] = new Trie();
			node = node->next[ch - 'a'];
		}
		node->terminated = true;
	}

	bool search(string word) {
		Trie *node = this;
		for (const char ch : word) {
			if (!node->next[ch - 'a']) return false;
			node = node->next[ch - 'a'];
		}
		return node->terminated;
	}

	bool startsWith(string prefix) {
		Trie *node = this;
		for (const char ch : prefix) {
			if (!node->next[ch - 'a']) return false;
			node = node->next[ch - 'a'];
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
