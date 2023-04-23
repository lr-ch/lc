/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int numberOfArrays(string s, int k) {
		vector<int> dp(s.length() + 1, 0);
		dp[0] = 1;

		for (int left = 0; left < s.length(); left++) {
			if (s[left] == '0') continue;	// skip leading 0

			for (int right = left; right < s.length(); right++) {
				// skip all numbers, they all be larger since this digit
				if (stol(s.substr(left, right - left + 1)) > k) break;

				dp[right + 1] += dp[left];
				dp[right + 1] %= MOD;
			}
		}
		return dp[s.length()];
	}
};
// @lc code=end
