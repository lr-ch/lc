/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
	int dp(string& s, int begin, int end) {
		if (begin >= end) return 0;

		if (memo[begin][end] != -1) return memo[begin][end];

		if (s[begin] == s[end])
			memo[begin][end] = dp(s, begin + 1, end - 1);
		else
			memo[begin][end] = 1 + min(
									dp(s, begin + 1, end),		// insert at begin
									dp(s, begin, end - 1));		// or insert at end
		return memo[begin][end];
	}

	vector<vector<int>> memo;
public:
	int minInsertions(string s) {
		memo.resize(s.length(), vector<int>(s.length(), -1));
		return dp(s, 0, s.length() - 1);
	}
};
// @lc code=end
