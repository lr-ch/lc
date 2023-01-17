/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int N = s.length();
		vector<pair<int, int>> dp(N + 1);	// vector[i].first  -> flip times at s[i] == '0'
											// vector[i].second -> flip times at s[i] == '1'
		for (int i = 1; i <= N; i++) {
			if (s[i - 1] == '0') {
				// no flip
				dp[i].first = dp[i - 1].first;
				// flip to 1, flip times + 1
				dp[i].second = min(dp[i - 1].first, dp[i - 1].second) + 1;
			} else {
				// flip to 0, flip times + 1
				dp[i].first = dp[i - 1].first + 1;
				// no flip
				dp[i].second = min(dp[i - 1].first, dp[i - 1].second);
			}
		}
		return min(dp[N].first, dp[N].second);
	}
};
// @lc code=end
