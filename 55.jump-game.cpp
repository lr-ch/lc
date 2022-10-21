/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int offset = 0;
		for (int dis = 0; offset < nums.size() && offset <= dis; offset++)
			dis = max(dis, nums[offset] + offset);
		return offset >= nums.size();
	}
};
// @lc code=end

