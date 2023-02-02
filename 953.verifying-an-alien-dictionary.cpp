/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class SolutionIntuition {
public:
	bool isAlienSorted(vector<string>& words, string& order) {
		array<char, 26> dict;
		for (int i = 0; i < order.size(); ++i) dict[order[i] - 'a'] = i;

		for (int i = 1; i < words.size(); ++i) {
			for (int j = 0; j < min(words[i - 1].size(), words[i].size()); j++) {
				if (words[i - 1][j] == words[i][j]) continue;

				if (dict[words[i - 1][j] - 'a'] > dict[words[i][j] - 'a'])
					return false;
				else
					break;
			}
			if (words[i - 1].size() > words[i].size() &&
				words[i - 1].substr(0, words[i].size()) == words[i])
				return false;
		}
		return true;
	}
};

class SolutionSTL {
public:
	bool isAlienSorted(vector<string>& words, string& order) {
		array<char, 26> dict;
		for (int i = 0; i < order.size(); ++i) dict[order[i] - 'a'] = i;

		for (string& word : words)
			for (char& ch : word)
				ch = dict[ch - 'a'];

		return is_sorted(words.begin(), words.end());
	}
};

class Solution {
	SolutionIntuition intui;
	SolutionSTL stl;
public:
	bool isAlienSorted(vector<string>& words, string order) {
	//	return intui.isAlienSorted(words, order);
		return stl.isAlienSorted(words, order);
	}
};
// @lc code=end
