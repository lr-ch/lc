/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n + 1, 1);

		// base cases
		if (n == 1) return 1;
		if (n == 2) return 2;

		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
	}
};
// @lc code=end

