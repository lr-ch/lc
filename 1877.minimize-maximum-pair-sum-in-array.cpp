/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution {
public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int maxPairSum = INT_MIN;
		int left = 0, right = nums.size() - 1;
		while (left < right)
			maxPairSum = max(maxPairSum, nums[left++] + nums[right--]);

		return maxPairSum;
	}
};
// @lc code=end
