/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
	int helper(vector<int>& nums, int goal) {

		int sum = 0, ret = 0;

		for (auto left = nums.begin(), right = left; right != nums.end(); right++) {
			sum += *right;

			while (sum > goal && left <= right) {
				sum -= *left;
				left++;
			}

			ret += right - left + 1;
		}

		return ret;
	}

public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		return helper(nums, goal) - helper(nums, goal - 1);
	}
};
// @lc code=end
