/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
	bool isDigit(const char& c) {
		return (c >= '0' && c <= '9') ? true : false;
	}
	bool isAlpha(const char& c) {
		return ((c >= 'a' && c <= 'z') ||
				(c >= 'A' && c <= 'Z')) ? true : false;
	}
	bool isSpace(const char& c) {
		return c == ' ' ? true : false;
	}
public:
	int myAtoi(string s) {
		bool isCalculated = false;
		long double ans = 0;
		long double sign = 1;
		for (int i = 0; i < s.length(); i++) {
			if (isDigit(s[i])) {
				isCalculated = true;
				ans = ans * 10 + (s[i] - '0');
			} else if (s[i] == '-' && i + 1 < s.length() && isDigit(s[i + 1]) && !isCalculated) {
				sign = -1;
				continue;
			} else if (s[i] == '+' && i + 1 < s.length() && isDigit(s[i + 1]) && !isCalculated) {
				continue;
			} else if (isAlpha(s[i])) {
				break;
			} else if (isSpace(s[i]) && !isCalculated) {
				continue;
			} else
				break;
		}

		if (ans * sign > INT_MAX) return INT_MAX;
		if (ans * sign < INT_MIN) return INT_MIN;
		return ans * sign;
	}
};
// @lc code=end

