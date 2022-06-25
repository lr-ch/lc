/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		for (int i = 0, counter = 0; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				if (counter++ == 1) return false;
				if (i >= 1) {
					if (nums[i - 1] > nums[i + 1])
						nums[i + 1] = nums[i];
					else
						nums[i] = nums[i - 1];
				}
			}
		}
		return true;
	}
};
// @lc code=end

