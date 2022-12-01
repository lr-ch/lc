/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
	set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
public:
	bool halvesAreAlike(string s) {
		int count1 = 0, count2 = 0;
		for (char& ch : s.substr(0, s.length() / 2)) count1 += vowels.count(ch);
		for (char& ch : s.substr(s.length() / 2, string::npos)) count2 += vowels.count(ch);
		return count1 == count2;
	}
};
// @lc code=end
