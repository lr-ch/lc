/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
	string dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	string convertToTitle(int columnNumber) {
		string res = "";
		do {
			res = dict[(columnNumber - 1) % 26] + res;
			columnNumber = (columnNumber - 1) / 26;
		} while (columnNumber);
		return res;
	}
};
// @lc code=end
