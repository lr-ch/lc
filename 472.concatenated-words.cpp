/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
	/*
	 * Shamelessly copied from Problem#139
	 * Ref. https://github.com/lr-ch/lc/blob/main/139.word-break.cpp
	 */
	int dfs(string& s, set<string>& d, vector<int>& m, int at) {
		if (at >= s.length()) return 1;
		if (m[at] != -1) return m[at];

		for (int cut = at + 1; cut <= s.length(); cut++) {
			string tmp = s.substr(at, cut - at);
			if (d.count(tmp) && dfs(s, d, m, cut)) {
				m[at] = 1;
				return m[at];
			}
		}

		m[at] = 0;
		return m[at];
	}

	bool wordBreak(string s, set<string>& dict) {
		vector<int> memo(s.length(), -1);
		return dfs(s, dict, memo, 0) == 1;
	}

public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		set<string> dict(words.begin(), words.end());
		vector<string> res;

		for (const auto& word : words) {
			dict.erase(word);
			if (wordBreak(word, dict))
				res.push_back(word);
			dict.insert(word);
		}

		return res;
	}
};
// @lc code=end
