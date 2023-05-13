/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int countGoodStrings(int low, int high, int zero, int one) {
		vector<int> dp(high + 1, 0);
		int ans = 0;

		dp[0] = 1;
		for (int i = 1; i <= high; i++) {
			// append '0' zero times
			if (i - zero >= 0)
				dp[i] = dp[i - zero] % MOD;

			// or append '1' one times
			if (i - one >= 0)
				dp[i] += dp[i - one] % MOD;

			if (low <= i && i <= high)
				ans = ((long)ans + dp[i]) % MOD;
		}

		return ans;
	}
};
// @lc code=end
