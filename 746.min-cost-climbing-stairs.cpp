/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
	int dp(vector<int>& cost, int i, vector<int>& memo) {
		if (i > cost.size() - 1) return 0;
		if (memo[i] != -1) return memo[i];

		int minCost = cost[i] + min(dp(cost, i + 1, memo), dp(cost, i + 2, memo));
		memo[i] = minCost;

		return minCost;
	}

public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> memo(cost.size(), -1);

		// Constraints:
		//   2 <= cost.length <= 1000
		return min(dp(cost, 0, memo), dp(cost, 1, memo));
	}
};
// @lc code=end

