/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
	bool match(const string& a, const string& b) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '.') continue;
			if (a[i] != b[i]) return false;
		}
		return true;
	}

	unordered_set<string> dict;
	unordered_map<int, unordered_set<string>> dict_with_len;
public:
	WordDictionary() {
	}

	void addWord(string word) {
		dict.insert(word);
		dict_with_len[word.length()].insert(word);
	}

	bool search(string word) {
		if (word.find('.') == string::npos)
			return dict.count(word);

		for (const auto& str : dict_with_len[word.length()])
			if (match(word, str)) return true;

		return false;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
