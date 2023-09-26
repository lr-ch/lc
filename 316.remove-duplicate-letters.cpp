/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> freq(26, 0);
		for (const auto& ch : s) freq[ch - 'a']++;

		string ret;
		for (const auto& ch : s) {
			freq[ch - 'a']--;

			// skip if ch already presents
			if (ret.find(ch) != string::npos) continue;

			// treat string as monotonic stack, remove elements if
			// 1. the back() is bigger than curr char and
			// 2. there still are remain freq[back()]
			while (!ret.empty() && ret.back() > ch && freq[ret.back() - 'a'] > 0)
				ret.pop_back();

			ret += ch;
		}
		return ret;
	}
};
// @lc code=end
