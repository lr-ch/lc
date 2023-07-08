/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0, sum = 0, ans = INT_MAX;

		for (int right = 0; right < nums.size(); right++) {
			sum += nums[right];

			while (sum >= target) {
				ans = min(ans, right - left + 1);
				sum -= nums[left++];
			}
		}

		return ans == INT_MAX ? 0 : ans;
	}
};
// @lc code=end
