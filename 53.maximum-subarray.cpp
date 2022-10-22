/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> memo(nums.size(), INT_MIN);

		memo[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			memo[i] = max(nums[i] + memo[i - 1], nums[i]);

		return *max_element(memo.begin(), memo.end());
	}
};
// @lc code=end
