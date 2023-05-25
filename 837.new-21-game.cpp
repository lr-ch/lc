/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution {
public:
	double new21Game(int n, int k, int maxPts) {
		if (k == 0 || n >= k + maxPts) return 1.0;

		vector<double> dp(n + 1);	// dp[i] : chance to get i points
		dp[0] = 1.0;
		double sum = 1.0, ans = 0;

		/*
		 * e.g. n = 8, k = 3, maxPts = 10
		 *   dp[1] -> 0.1
		 *   dp[2] -> 0.1 + 0.1 * 0.1 (draw 2 points, draw 1 point 2-times)
		 *         => 0.1 * (1 + 0.1)
		 *   dp[3] -> 0.1 (draw 3 points)
		 *          + 0.1 * 0.1 (draw 1 point and draw 2 points)
		 *          + 0.1 * 0.1 (draw 2 points and draw 1 point)
		 *          + 0.1 * 0.1 * 0.1 (draw 1 point 3-times)
		 *         => 0.1 * (1 + 0.1 + 0.11)
		 *   dp[4] -> 0.1 * 0.1 * 0.1 * 0.1 is not considered
		 *         => 0.1 * (1 + 0.1 + 0.11 + 0.111)
		 */
		for (int i = 1; i <= n; i++) {
			dp[i] = sum / maxPts;

			if (i < k)
				sum += dp[i];
			else
				ans += dp[i];

			if (i - maxPts >= 0)
				sum -= dp[i - maxPts];
		}
		return ans;
	}
};
// @lc code=end
