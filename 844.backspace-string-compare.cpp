/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string s1, t1;
		int len = max(s.length(), t.length());

		for (int i = 0; i < len; i++) {
			if (i < s.length()) {
				if (s[i] != '#') s1.push_back(s[i]);
				else if (!s1.empty()) s1.pop_back();
			}
			if (i < t.length()) {
				if (t[i] != '#') t1.push_back(t[i]);
				else if (!t1.empty()) t1.pop_back();
			}
		}

		return s1 == t1;
	}
};
// @lc code=end
