/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;

		// shrink search area
		while (left <= right && nums[left] == nums[right]) {
			if (target == nums[left]) return true;
			left++;
			right--;
		}

		// copy from 33. Search in Rotated Sorted Array
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return true;
			if (nums[mid] > nums[right]) {
				if (nums[left] <= target && nums[mid] > target)
					right = mid - 1;
				else
					left = mid + 1;
			} else {
				if (nums[mid] < target && nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return false;
	}
};
// @lc code=end
