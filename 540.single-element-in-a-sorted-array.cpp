/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() < 2) return nums[nums.size() - 1];

		int left = 0, right = nums.size() - 1, mid;

		while (left < right) {
			mid = left + (right - left) / 2;

			if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
				return nums[mid];

			if (mid % 2) {
				if (nums[mid - 1] == nums[mid]) left = mid + 1;
				else right = mid - 1;
			} else {
				if (nums[mid - 1] == nums[mid]) right = mid - 2;
				else left = mid + 1;
			}
		}
		return nums[left];
	}
};
// @lc code=end
