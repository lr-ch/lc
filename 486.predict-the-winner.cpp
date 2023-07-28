/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
	// from sub-array nums[left .. right], pick max difference of (my score - opponent score)
	int score(vector<int>& nums, int left, int right) {
		if (left == right) return nums[left];
		return max(
				nums[left] - score(nums, left + 1, right),
				nums[right] - score(nums, left, right - 1)
				);
	}
public:
	bool PredictTheWinner(vector<int>& nums) {
		return score(nums, 0, nums.size() - 1) >= 0;
	}
};
// @lc code=end
