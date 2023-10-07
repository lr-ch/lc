/*
 * @lc app=leetcode id=1420 lang=cpp
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */

// @lc code=start
class Solution {
	int dfs(int n, int m, int k) {
		if (k > m || k > n || k < 1) return 0;
		if (1 == n && k == 1) return m;

		if (dp[n][m][k] != 0) return dp[n][m][k];

		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += dfs(n - 1, m, k);
			ans += dfs(n - 1, i - 1, k - 1);
			ans -= dfs(n - 1, i - 1, k);
			ans += MOD;
			ans %= MOD;
		}
		return dp[n][m][k] = static_cast<int>(ans);
	}

	/*
	 * dp[n][m][k] := number of arrays with n elements, max element of the array[1..n] is m and search cost is k
	 *  -> if array[n] is happen to the max element m --> dp[n][m][k] = sum(dp[n - 1][1..(m-1)][k - 1])
	 *     sum of number of arrays with [n - 1] elements and m - 1 is the max elements with search cost k - 1
	 *
	 *  -> if array[n] is not the max element m --> dp[n][m][k] = sum(dp[n - 1][1..m][k])
	 *     e.g 1,7,3,4,? -> n is 5, m is 7, here "?" can only be 1~7 => [1,7,3,4,1][1,7,3,4,2]...[1,7,3,4,7]
	 */
	vector<vector<vector<int>>> dp;
	const int MOD = 1e9 + 7;
public:
	int numOfArrays(int n, int m, int k) {
		dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
		return dfs(n, m, k);
	}
};
// @lc code=end
