/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
	bool isSubsequence(string s, string t) {
		auto ps = s.begin(), pt = t.begin();

		while (pt != t.end() && ps != s.end()) {
			if (*ps == *pt) ps++;
			pt++;
		}

		return ps == s.end();
	}
};
// @lc code=end
