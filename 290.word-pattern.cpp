/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		istringstream iss(s);
		vector<string> words;

		do {
			string subs;
			iss >> subs;
			words.push_back(subs);
		} while (iss);

		// NOTE. words.size() contains an additional null character
		if (words.size() - 1 != pattern.length()) return false;

		unordered_map<char, string> mp;
		set<string> st;

		for (int i = 0; i < pattern.length(); i++) {
			char ch = pattern[i];
			string word = words[i];

			if (mp.count(ch)) {
				// ch is mapping to the same word?
				if (mp[ch] != word)
					return false;
			} else {
				// word is mapping to the same ch?
				if (st.count(word) != 0)
					return false;

				mp[ch] = word;
				st.insert(word);
			}
		}
		return true;
	}
};
// @lc code=end
