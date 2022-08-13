/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s == "" || words.size() == 0) return {};

		int word_len = words[0].length();	// all words have the same length
		int word_count = words.size();

		// if s is shorter than total length of words
		if (word_len * word_count > s.size()) return {};

		map<string, int> dict;				// [word, count]
		vector<int> ans;

		for (auto& w : words) dict[w]++;	// words may contain repeated word

		for (int i = 0; i <= s.size() - word_len * word_count; i++) {
			map<string, int> copy = dict;

			int j = i;
			int count = word_count;

			while (count > 0) {
				string comp_str = s.substr(j, word_len);
				// if the string is not in dict
				if (copy.count(comp_str) == 0)
					break;

				// if the word appears too many times
				if (--copy[comp_str] < 0)
					break;

				count--;
				j += word_len;
			}
			if (count == 0) ans.push_back(i);
		}

		return ans;
	}
};
// @lc code=end
