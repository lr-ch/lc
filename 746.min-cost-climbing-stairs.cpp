/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class SolutionRecur {
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

class SolutionItera {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> memo(n, 0);

		memo[0] = cost[0];
		memo[1] = cost[1];	// memo[1] = min(cost[0] + cost[1], cost[1])

		for (int i = 2; i < n; i++)
			memo[i] = cost[i] + min(memo[i - 1], memo[i - 2]);
		return min(memo[n - 1], memo[n - 2]);
	}
};

class Solution {
	SolutionRecur recur;
	SolutionItera itera;
public:
	int minCostClimbingStairs(vector<int>& cost) {
	//	return recur.minCostClimbingStairs(cost);
		return itera.minCostClimbingStairs(cost);
	}
};
// @lc code=end

