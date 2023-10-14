/*
 * @lc app=leetcode id=2742 lang=cpp
 *
 * [2742] Painting the Walls
 */

// @lc code=start
class Solution {
	/*
	 * dp[i][j] := the minimun cost with first i workers and remain walls j
	 */
	int dp(vector<int>& c, vector<int>& t, int i, int j) {
		if (j <= 0) return 0;				// no more walls to paint
		if (i == c.size()) return 1e9 + 7;	// no more paid painter
		if (memo[i][j] != -1) return memo[i][j];

		int paint = c[i] + dp(c, t, i + 1, j - 1 - t[i]),	// pick painter#i
			no_paint = dp(c, t, i + 1, j);					// pick free painter
		return memo[i][j] = min(paint, no_paint);
	}

	vector<vector<int>> memo;
public:
	int paintWalls(vector<int>& cost, vector<int>& time) {
		memo.assign(cost.size(), vector<int>(cost.size() + 1, -1));
		return dp(cost, time, 0, cost.size());
	}
};
// @lc code=end
