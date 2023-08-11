/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class SolutionTopDown {
	int dp(int curr, const vector<int>& coins, int index) {
		if (curr == 0) return 1;
		if (curr < 0 || index >= coins.size()) return 0;

		if (memo[curr][index] != -1) return memo[curr][index];

		return memo[curr][index] =
				// check whether this coin value is larger than current target
				coins[index] > curr ?
					// this coin is too large, skip it and take next
					dp(curr, coins, index + 1) :
					// this coin is ok to pick or we can still skip it to take next
					memo[curr][index] = dp(curr - coins[index], coins, index) + dp(curr, coins, index + 1);
	}

	vector<vector<int>> memo;
public:
	int change(int amount, vector<int>& coins) {
		memo.resize(amount + 1, vector<int>(coins.size(), -1));
		return dp(amount, coins, 0);
	}
};

class SolutionBottomUp {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1);
		dp[0] = 1;

		for (int i = 0; i < coins.size(); i++)
			for (int j = coins[i]; j <= amount; j++)
				dp[j] += dp[j - coins[i]];

		return dp[amount];
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 28/28 cases passed (39 ms)
	 *  - Your runtime beats 43.11 % of cpp submissions
	 *  - Your memory usage beats 11.46 % of cpp submissions (21.7 MB)
	 */
	SolutionTopDown td;

	/*
	 * Accepted
	 *  - 28/28 cases passed (3 ms)
	 *  - Your runtime beats 99.13 % of cpp submissions
	 *  - Your memory usage beats 86.45 % of cpp submissions (7.2 MB)
	 */
	SolutionBottomUp bu;
public:
	int change(int amount, vector<int>& coins) {
	//	return td.change(amount, coins);
		return bu.change(amount, coins);
	}
};
// @lc code=end
