/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */

// @lc code=start
class Solution {
public:
	string reformat(string s) {
		string digit;
		string chars;
		string ans;

		for (const auto& ch : s) {
			if (ch >= 'a' && ch <= 'z') digit += ch;
			if (ch >= '0' && ch <= '9') chars += ch;
		}

		if (abs((int)digit.length() - (int)chars.length()) <= 1) {
			for (int i = 0; i < min(digit.size(), chars.size()); i++) {
				ans += digit[i];
				ans += chars[i];
			}

			if (digit.size() > chars.size())
				ans = ans + digit.back();

			if (chars.size() > digit.size())
				ans = chars.back() + ans;
		}

		return ans;
	}
};
// @lc code=end
