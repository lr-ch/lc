/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
	int dp(vector<vector<int>>& m, int r, int c, vector<vector<int>>& t) {
		// check boundary
		if (r >= R || r < 0 || c >= C || c < 0) return 10001;
		if (r == 0) return m[0][c];

		if (t[r][c] < 10001) return t[r][c];

		t[r][c] = m[r][c] + min({
								dp(m, r - 1, c - 1, t),
								dp(m, r - 1,   c  , t),
								dp(m, r - 1, c + 1, t)
							});

		return t[r][c];
	}

	int R, C;
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		R = matrix.size(), C = matrix[0].size();
		vector<vector<int>> memo(R, vector<int>(C, 10001));

		int ans = INT_MAX;
		for (int i = 0; i < C; i++)
			ans = min(ans, dp(matrix, R - 1, i, memo));

		return ans;
	}
};
// @lc code=end
