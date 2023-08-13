/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

// @lc code=start
class Solution {
public:
	bool validPartition(vector<int>& nums) {
		vector<bool> dp(nums.size() + 1, false);	// dp[i] = true if a valid pation method exists before #i-th number

		// base cases
		dp[0] = true;	// assume an empty partion is valid
		dp[1] = false;	// impossible if partion contains only 1 number

		// the only valid partion method for two numbers is they are the same
		if (nums.size() >= 2) dp[2] = (nums[0] == nums[1]);

		for (int i = 3; i <= nums.size(); i++)
			dp[i] = (nums[i - 1] == nums[i - 2] && dp[i - 2]) ||
					(nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3] && dp[i - 3]) ||
					(nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1 && dp[i - 3]);

		return dp[nums.size()];
	}
};
// @lc code=end
