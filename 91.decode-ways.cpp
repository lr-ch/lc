/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
	int dp(string s, vector<int>& memo) {
		if (s.length() == 0) return 1;
		if (memo[s.length()] != 0) return memo[s.length()];

		// 1-digit
		if (s[0] >= '1' && s[0] <= '9')
			memo[s.length()] = dp(s.substr(1), memo);

		// 2-digits
		if (s.length() > 1) {
			int two_digits = atoi(s.substr(0, 2).c_str());
			if (two_digits >= 10 && two_digits <= 26)
				memo[s.length()] += dp(s.substr(2), memo);
		}

		return memo[s.length()];
	}

public:
	int numDecodings(string s) {
		vector<int> memo(s.length() + 1, 0);
		return dp(s, memo);
	}
};
// @lc code=end

