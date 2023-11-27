/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
	const vector<vector<int>> moves = {
		{4, 6},		// to "0"
		{6, 8},		// to "1"
		{7, 9},		// 2
		{4, 8},		// 3
		{3, 9, 0},	// 4
		{},			// 5
		{1, 7, 0},	// 6
		{2, 6},
		{1, 3},
		{2, 4}
	};
public:
	int knightDialer(int n) {
		vector<vector<int>> dp(n, vector<int>(10, 0));
		for (int i = 0; i < 10; i++) dp[0][i] = 1;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				int sum = 0;
				for (auto& next : moves[j])
					sum = (sum + dp[i - 1][next]) % MOD;

				dp[i][j] = sum;
			}
		}

		int ans = 0;
		for (int i = 0; i < 10; i++)
			ans = (ans + dp[n - 1][i]) % MOD;
		return ans;
	}
};
// @lc code=end
