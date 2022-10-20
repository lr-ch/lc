/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
	int dp(vector<int> n) {
		fill(memo.begin(), memo.end(), -1);

		if (n.size() == 1) return n[0];

		memo[0] = n[0];
		memo[1] = max(memo[0], n[1]);

		for (int i = 2; i < n.size(); i++)
			memo[i] = max(memo[i - 2] + n[i], memo[i - 1]);
		return memo[n.size() - 1];
	}

	array<int, 101> memo;
public:
	int rob(vector<int>& nums) {
		if (nums.size() < 2) return nums[0];
		int startFromFirstHouse = dp(vector<int>(nums.begin(), nums.end() - 1));
		int startFromSecondHouse = dp(vector<int>(nums.begin() + 1, nums.end()));
		return max(startFromFirstHouse, startFromSecondHouse);
	}
};
// @lc code=end
