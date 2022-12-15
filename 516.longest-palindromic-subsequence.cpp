/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int length = s.length();

		// dp[i][j] = the LPS length in s[i..j]
		vector<vector<int>> dp(length, vector<int>(length));

		// base case
		for (int i = 0; i < length; i++) dp[i][i] = 1;

		for (int i = length - 1; i >= 0; i--)
			for (int j = i + 1; j < length; j++)
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

		return dp[0][length - 1];
	}
};
// @lc code=end

