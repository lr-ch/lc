/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class SolutionTopBottom {
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
		dp.resize(M, vector<int>(N, -1));

		return dfs(word1, M - 1, word2, N - 1);
	}
};

class SolutionBottomTop {
	array<array<int, 501>, 501> dp;
public:
	int minDistance(string word1, string word2) {
		int M = word1.length(), N = word2.length();

		// base case
		for (int i = 0; i <= M; i++) dp[i][0] = i;
		for (int j = 0; j <= N; j++) dp[0][j] = j;

		for (int x = 1; x <= M; x++) {
			for (int y = 1; y <= N; y++) {
				if (word1[x - 1] == word2[y - 1]) {
					dp[x][y] = dp[x - 1][y - 1];	// do nothing
				} else {
					dp[x][y] = min({
						dp[x][y - 1] + 1,			// insert
						dp[x - 1][y - 1] + 1,		// modify
						dp[x - 1][y] + 1			// delete
					});
				}
			}
		}
		return dp[M][N];
	}
};

class Solution {
	/*
	 * Accepted
	 *  1146/1146 cases passed (6 ms)
	 *  Your runtime beats 93.28 % of cpp submissions
	 *  Your memory usage beats 63.2 % of cpp submissions (9 MB)
	 */
	SolutionTopBottom top;

	/*
	 * Accepted
	 *  1146/1146 cases passed (23 ms)
	 *  Your runtime beats 32.97 % of cpp submissions
	 *  Your memory usage beats 72.1 % of cpp submissions (8.9 MB)
	 */
	SolutionBottomTop bottom;
public:
	int minDistance(string word1, string word2) {
	//	return top.minDistance(word1, word2);
		return bottom.minDistance(word1, word2);
	}
};
// @lc code=end
