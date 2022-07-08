/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */

// @lc code=start
class Solution {
	/*
	 * @ref: https://leetcode.com/problems/paint-house-iii/discuss/2252980/
	 *
	 * cost : dp[index of current house][last house color][neighbors count]
	 *
	 */
	const int INF = 1e9 + 7;
	vector<vector<vector<int>>> memo;

	int dp(vector<int>& h, vector<vector<int>>& c, int m, int n, int t, int ich, int lhc, int nc) {
	//	cout << ich << ":" << lhc << ":" << nc << endl;
		if (nc > t) return INF;
		if (ich == m) return nc == t ? 0 : INF;
		if (memo[ich][lhc][nc] != -1) return memo[ich][lhc][nc];

		// if current house is painted, go next one
		if (h[ich])
			return memo[ich][lhc][nc] = dp(h, c, m, n, t, ich + 1, h[ich], h[ich] == lhc ? nc : nc + 1);

		int ans = INF;
		for (int i = 0; i < n; i++) {
			// pick a color for painting, and go next one
			int cost = c[ich][i] + dp(h, c, m, n, t, ich + 1, i + 1, i + 1 == lhc ? nc : nc + 1);
		//	cout << "cost :" << cost << endl;
			ans = min(ans, cost);
		}

		// record the minimun cost
		return memo[ich][lhc][nc] = ans;
	}

public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		memo.assign(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
		int ans = dp(houses, cost, m, n, target, 0, 0, 0);
		return ans == INF ? -1 : ans;
	}
};
// @lc code=end

