/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {
		long long ans = 0, count = 0;
		for (const auto& n : nums) {
			count = (n == 0 ? count + 1 : 0);
			ans += count;
		}
		return ans;
	}
};
// @lc code=end
