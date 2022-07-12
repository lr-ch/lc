/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
	int dp(vector<int>& coins, int amount, map<int, int>& memo) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;

		auto iter = memo.find(amount);
		if (iter != memo.end())
			return iter->second;

		int ans = INT_MAX;
		for (auto c : coins) {
			int result = dp(coins, amount - c, memo);
			if (result != -1)
				ans = min(ans, result + 1);
		}

		if (ans == INT_MAX)
			ans = -1;

		memo.insert(pair<int, int>(amount, ans));

		return memo.find(amount)->second;
	}

public:
	int coinChange(vector<int>& coins, int amount) {
		map<int, int> memo;
		return dp(coins, amount, memo);
	}
};
// @lc code=end

