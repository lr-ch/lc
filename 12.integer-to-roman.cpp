/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
	vector<pair<int, string>> dict {
		{1000,	"M"},
		{900,	"CM"},
		{500,	"D"},
		{400,	"CD"},
		{100,	"C"},
		{90,	"XC"},
		{50,	"L"},
		{40,	"XL"},
		{10,	"X"},
		{9,		"IX"},
		{5,		"V"},
		{4,		"IV"},
		{1,		"I"} };

public:
	string intToRoman(int num) {
		string ans = "";
		while (num) {
			for (auto& p : dict) {
				if (num >= p.first) {
					ans += p.second;
					num -= p.first;
					break;
				}
			}
		}
		return ans;
	}
};
// @lc code=end

