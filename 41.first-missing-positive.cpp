/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			while (!(
				nums[i] <= 0 || nums[i] > nums.size() ||	// out of boundary
				nums[i] == nums[nums[i] - 1]				// duplicated
			))
				swap(nums[i], nums[nums[i] - 1]);
		}

		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1)
				return i + 1;

		// in case no losing number
		// e.g. [1, 2, 3] -> return 4
		return nums.back() + 1;
	}
};
// @lc code=end
