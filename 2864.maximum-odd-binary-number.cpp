/*
 * @lc app=leetcode id=2864 lang=cpp
 *
 * [2864] Maximum Odd Binary Number
 */

// @lc code=start
class Solution {
public:
	string maximumOddBinaryNumber(string s) {
		int how_many_1s = count(s.begin(), s.end(), '1');
		return string(how_many_1s - 1, '1') +
				string(s.size() - how_many_1s, '0') +
				'1';
	}
};
// @lc code=end
