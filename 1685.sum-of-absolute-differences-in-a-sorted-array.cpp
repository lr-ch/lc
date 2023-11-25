/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		vector<int> preSum(nums.size(), 0);
		preSum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			preSum[i] = preSum[i - 1] + nums[i];

		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			int lsum = preSum[i] - nums[i];
			int rsum = preSum.back() - preSum[i];

			int ltotal = i * nums[i] - lsum;
			int rtotal = rsum - (nums.size() - 1 - i) * nums[i];
			ans.push_back(ltotal + rtotal);
		}
		return ans;
	}
};
// @lc code=end
