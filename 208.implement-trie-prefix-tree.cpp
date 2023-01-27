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
		terminated = false;
	}

	void insert(string word) {
		if (word.empty()) {
			this->terminated = true;
			return;
		}

		if (this->next[word[0] - 'a'] == nullptr)
			this->next[word[0] - 'a'] = new Trie();

		this->next[word[0] - 'a']->insert(word.substr(1));
	}

	bool search(string word) {
		if (word.empty()) return this->terminated;

		if (this->next[word[0] - 'a'] == nullptr) return false;

		return this->next[word[0] - 'a']->search(word.substr(1));
	}

	bool startsWith(string prefix) {
		if (prefix.empty()) return true;

		if (this->next[prefix[0] - 'a'] == nullptr) return false;

		return this->next[prefix[0] - 'a']->startsWith(prefix.substr(1));
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
