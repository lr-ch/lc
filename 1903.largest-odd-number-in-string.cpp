/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
class Solution {
public:
	string largestOddNumber(string num) {
		for (int i = num.length() - 1; i >= 0; i--)
			if ((num[i] - '0') % 2)
				return num.substr(0, i + 1);
		return "";
	}
};
// @lc code=end
