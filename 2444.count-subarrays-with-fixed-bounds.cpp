/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution {
public:
	long long countSubarrays(vector<int>& nums, int minK, int maxK) {
		int left = -1, right = 0, mini = -1, maxi = -1;
		long long res = 0;
		while (right < nums.size()) {
			// if nums[i] overflow/underflow the boundary
			if (nums[right] < minK || nums[right] > maxK)
				left = right;

			if (nums[right] == minK) mini = right;
			if (nums[right] == maxK) maxi = right;

			res += max(0, min(mini, maxi) - left);

			right++;
		}
		return res;
	}
};
// @lc code=end
