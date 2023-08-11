/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
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
// @lc code=end
