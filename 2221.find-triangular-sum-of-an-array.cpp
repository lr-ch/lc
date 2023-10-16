/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */

// @lc code=start
class Solution {
public:
	int triangularSum(vector<int>& nums) {
		for (int n = nums.size(); n != 1; n--)
			for (int i = 1; i < n; i++)
				nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
		return nums.front();
	}
};
// @lc code=end
