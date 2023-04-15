/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
 */

// @lc code=start
class Solution {
	int dfs(int pile_id, int k) {
		if (k == 0) return 0;

		if (pile_id >= knapsack.size() || k < 0) return INT_MIN;

		if (memo[pile_id][k] != INT_MIN) return memo[pile_id][k];

		for (int i = 0; i < knapsack[pile_id].size(); i++)
			memo[pile_id][k] = max({
									memo[pile_id][k],
									// select i piles in this pile, try k - i - 1 in remain piles
									knapsack[pile_id][i] + dfs(pile_id + 1, k - i - 1),
									// select none piles in this pile, try k in remain piles
									dfs(pile_id + 1, k)
								});
		return memo[pile_id][k];
	}

	vector<vector<int>> knapsack;
	vector<vector<int>> memo;
public:
	int maxValueOfCoins(vector<vector<int>>& piles, int k) {
		// transfer into knapsack problem
		// 1. create prefix sum table for every pile
		for (const auto& pile : piles) {
			vector<int> preSum(pile.size(), 0);
			preSum[0] = pile[0];
			for (int i = 1; i < pile.size(); i++)
				preSum[i] = preSum[i - 1] + pile[i];
			knapsack.push_back(preSum);
		}

		memo.resize(knapsack.size() + 1, vector<int>(k + 1, INT_MIN));

		// 2. start dp
		return dfs(0, k);
	}
};
// @lc code=end
