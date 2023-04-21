/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
	int dfs(int n, int minP, vector<int>& gr, vector<int>& pr, int crime, int member, int profit) {
		if (crime >= pr.size()) return profit >= minP ? 1 : 0;

		if (dp[crime][member][profit] != -1) return dp[crime][member][profit];

		// skip this crime
		int schemes = dfs(n, minP, gr, pr, crime + 1, member, profit) % MOD;
		// do this crime
		if (member + gr[crime] <= n)
			schemes += dfs(n, minP, gr, pr, crime + 1, member + gr[crime], min(minP, profit + pr[crime])) % MOD;

		return dp[crime][member][profit] = schemes % MOD;
	}

	vector<vector<vector<int>>> dp;
	const int MOD = 1e9 + 7;
public:
	int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
		int crimes = profit.size();
		dp.resize(crimes + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

		return dfs(n, minProfit, group, profit, 0, 0, 0);
	}
};
// @lc code=end
