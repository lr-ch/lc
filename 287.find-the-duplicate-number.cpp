/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int fast = 0, slow = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (nums[slow] != nums[fast]);

		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return fast;
	}
};
// @lc code=end
