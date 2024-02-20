/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int total = (nums.size() + 1) * nums.size() / 2;
		return total - accumulate(nums.begin(), nums.end(), 0);
	}
};
// @lc code=end
