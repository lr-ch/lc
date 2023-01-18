/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
	/*
	 * ref. https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/178422/one-pass/
	 */
	int maxSubarraySumCircular(vector<int>& nums) {
		int max_sum = nums[0], min_sum = nums[0], sum = 0;

		for (int curr_max = 0, curr_min = 0, i = 0; i < nums.size(); i++) {
			curr_max = max(curr_max, 0) + nums[i];
			max_sum = max(max_sum, curr_max);

			curr_min = min(curr_min, 0) + nums[i];
			min_sum = min(min_sum, curr_min);

			sum += nums[i];
		}

		return max_sum < 0 ? max_sum : max(max_sum, sum - min_sum);
	}
};
// @lc code=end
