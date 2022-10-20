/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class SolutionRecur {
	int dp(vector<int>& n, int i) {
		if (i < 0) return 0;
		if (memo[i] != -1) return memo[i];

		memo[i] = max(n[i] + dp(n, i - 2), dp(n, i - 1));
		return memo[i];
	}

	array<int, 101> memo;
public:
	int rob(vector<int>& nums) {
		fill(memo.begin(), memo.end(), -1);
		return dp(nums, nums.size() - 1);
	}
};

class SolutionItera {
	array<int, 101> memo;
public:
	int rob(vector<int>& nums) {
		fill(memo.begin(), memo.end(), -1);

		if (nums.size() == 1) return nums[0];

		memo[0] = nums[0];
		memo[1] = max(memo[0], nums[1]);

		for (int i = 2; i < nums.size(); i++)
			memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
		return memo[nums.size() - 1];
	}
};

class Solution {
	SolutionRecur recur;
	SolutionItera itera;
public:
	int rob(vector<int>& nums) {
	//	return recur.rob(nums);
		return itera.rob(nums);
	}
};
// @lc code=end
