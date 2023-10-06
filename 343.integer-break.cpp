/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
	int dfs(int n) {
		if (memo[n] != -1) return memo[n];

		int ans = n;
		for (int i = 2; i < n; i++)
			ans = max(ans, i * dfs(n - i));

		return memo[n] = ans;
	}

	array<int, 59> memo;
public:
    int integerBreak(int n) {
		if (n == 2) return 1;	// 1 + 1
		if (n == 3) return 2;	// 1 + 2

		memo.fill(-1);
		return dfs(n);
    }
};
// @lc code=end
