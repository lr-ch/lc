/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
	bool isPalindromeString(const string &s) {
		size_t i1 = 0, i2 = s.length() - 1;
		while (i1 <= i2 && i1 < s.length() && i2 >= 0) {
			if (s[i1] != s[i2])
				return false;
			i1++; i2--;
		}
		return true;
	}
public:
	bool isPalindrome(int x) {
		string numstr = to_string(x);
		return isPalindromeString(numstr);
	}
};
// @lc code=end
