/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int ans = 1;
		for (int l = 0, r = 1; r < nums.size(); r++) {
			if (nums[r] > nums[r - 1])
				ans = max(ans, r - l + 1);
			else
				l = r;
		}
		return ans;
	}
};
// @lc code=end
