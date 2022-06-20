/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
	void reverseString(vector<char>& s) {
		vector<char>::iterator	f = s.begin(), b = s.end() - 1;
		while (f < b) {
			swap(*f, *b);
			f++; b--;
		}
	}
};
// @lc code=end

