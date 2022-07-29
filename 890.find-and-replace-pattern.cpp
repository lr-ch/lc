/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution {
	bool match(string& word, string& pattern) {
		map<char, char> map_w, map_p;

		for (int i = 0; i < word.size(); i++) {
			if (map_w.find(word[i]) == map_w.end())
				map_w.insert(pair<char, char>(word[i], pattern[i]));

			if (map_p.find(pattern[i]) == map_p.end())
				map_p.insert(pair<char, char>(pattern[i], word[i]));

			if (map_w[word[i]] != pattern[i] ||
				map_p[pattern[i]] != word[i])
				return false;
		}
		return true;
	}

public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans;

		for (int i = 0; i < words.size(); i++)
			if (match(words[i], pattern))
				ans.push_back(words[i]);

		return ans;
	}
};
// @lc code=end

