/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
	int dfs(string& w1, int m, string& w2, int n) {
		if (m < 0) return n + 1;
		if (n < 0) return m + 1;
		if (dp[m][n] != -1) return dp[m][n];

		if (w1[m] == w2[n]) {
			return dp[m][n] = dfs(w1, m - 1, w2, n - 1);	// do nothing
		} else {
			dp[m][n] = min({
				dfs(w1, m, w2, n - 1) + 1,			// insert character at w1[m]
				dfs(w1, m - 1, w2, n - 1) + 1,		// modify character at w1[m]
				dfs(w1, m - 1, w2, n) + 1			// delete character at w1[m]
			});
		}
		return dp[m][n];
	}

	vector<vector<int>> dp;
	int M, N;
public:
	int minDistance(string word1, string word2) {
		M = word1.length();
		N = word2.length();
		dp.resize(M + 1, vector<int>(N + 1, -1));

		return dfs(word1, M - 1, word2, N - 1);
	}
};
// @lc code=end
