/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
	int dp(int n, int k, int t) {
		if (n == 0) return t == 0 ? 1 : 0;
		if (t < 0) return 0;
		if (memo[n][t] != INT_MIN) return memo[n][t];

		long sum = 0;
		for (int i = 1; i <= k; i++)
			sum = (sum + dp(n - 1, k, t - i)) % MOD;
		memo[n][t] = sum % MOD;

		return memo[n][t];
	}

	const int MOD = 1e9 + 7;
	array<array<int, 1001>, 31> memo;
public:
	int numRollsToTarget(int n, int k, int target) {
		for (auto& arr : memo)
			fill(arr.begin(), arr.end(), INT_MIN);
		return dp(n, k, target);
	}
};
// @lc code=end
