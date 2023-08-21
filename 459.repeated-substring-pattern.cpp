/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.length();

		// if the pattern can be combined to be s, its length cannot exceed len / 2
		// e.g. abab -> ab, abcabc -> abc
		for (int i = len / 2; i >= 1; i--) {
			// the length of s should be divisable by pattern's length as well
			if (len % i == 0) {
				string pat = "";

				// now repeat the pattern (len / i) times and see whether it is s
				for (int j = 0; j < len / i; j++)
					pat += s.substr(0, i);
				if (pat == s) return true;
			}
		}
		return false;
	}
};
// @lc code=end
