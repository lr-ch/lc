/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution {
public:
	int minExtraChar(string s, vector<string>& dictionary) {
		unordered_set<string> dict(dictionary.begin(), dictionary.end());
		vector<int> dp(s.size() + 1);					// dp[i] : extra-chars in s[0:i]
		dp[0] = 0;										// no extra-chars in empty s
		for (int i = 1; i <= s.size(); i++) {
			dp[i] = dp[i - 1] + 1;						// assume s[i] is an extra-char
			for (int j = 0; j < i; j++)
				if (dict.count(s.substr(j, i - j)))		// now try to match s[j:i] in dict strings
					dp[i] = min(dp[i], dp[j]);
		}
		return dp[s.size()];
	}
};
// @lc code=end
