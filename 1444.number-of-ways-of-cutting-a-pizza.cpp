/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
	/*
	 * 304. Range Sum Query 2D - Immutable
	 */
	inline int hasApple(int c1, int r1, int c2, int r2) {
		return (apples[r2 + 1][c2 + 1] - apples[r2 + 1][c1] - apples[r1][c2 + 1] + apples[r1][c1] > 0) ? 1 : 0;
	}

	/*
	 * dp(m, n, k) -> ways of cut pizza[m][n] in k cuts
	 *             => sum(hasApple(left) * dp(right, k - 1)) +
	 *                sum(hasApple(top) * dp(bottom, k - 1))
	 */
	int dp(int m, int n, int k) {
		if (k == 0) return hasApple(n, m, C - 1, R - 1);
		if (memo[m][n][k] != -1) return memo[m][n][k];

		memo[m][n][k] = 0;
		for (int r = m; r < R - 1; r++)
			memo[m][n][k] = (memo[m][n][k] + hasApple(n, m, C - 1, r) * dp(r + 1, n, k - 1)) % MOD;
		for (int c = n; c < C - 1; c++)
			memo[m][n][k] = (memo[m][n][k] + hasApple(n, m, c, R - 1) * dp(m, c + 1, k - 1)) % MOD;
		return memo[m][n][k];
	}

	const int MOD = 1e9 + 7;
	int R, C;
	array<array<int, 51>, 51> apples;
	array<array<array<int, 10>, 50>, 50> memo;
public:
	int ways(vector<string>& pizza, int k) {
		R = pizza.size();
		C = pizza[0].size();

		for (auto& arr : apples)
			fill(arr.begin(), arr.end(), 0);
		for (int r = 0; r < R; r++)
			for(int c = 0; c < C; c++)
				apples[r + 1][c + 1] = apples[r + 1][c] + apples[r][c + 1] + (pizza[r][c] == 'A') - apples[r][c];

		for (auto& mm : memo)
			for (auto& m : mm)
				fill(m.begin(), m.end(), -1);

		return dp(0, 0, k - 1);
	}
};
// @lc code=end
