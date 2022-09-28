/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size(), i = 0;

		// step.1 re-arrange each number to its "correct" position
		// e.g. [3,4,-1,1]
		//   i = 0, nums[0] = 3, swap with nums[3 - 1] -> [-1,4,3,1]
		//   i = 1, nums[1] = 4, swap with nums[4 - 1] -> [-1,1,3,4]
		//   i = 1, nums[1] = 1, swap with nums[1 - 1] -> [1,-1,3,4]
		//   i = 2/3, nothing to do
		while (i < n)
			// take care of the index range!
			if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
			else
				i++;

		// step.2 search for the number which absents in its position
		// e.g. [1,-1,3,4] -> nums[1] should be 2, but here is -1
		for (int j = 0; j < n; j++)
			if (nums[j] != j + 1) return j + 1;

		// if nothing absents, return the end of nums
		return n + 1;
	}
};
// @lc code=end
