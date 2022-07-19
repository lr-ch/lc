/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto left_iter = find(nums.begin(), nums.end(), target);
		if (left_iter != nums.end()) {
			auto right_iter = upper_bound(nums.begin(), nums.end(), target);

			int left = distance(nums.begin(), left_iter);
			int right = distance(nums.begin(), right_iter) - 1;
			return {left, right};
		}

		return {-1, -1};
	}
};
// @lc code=end
