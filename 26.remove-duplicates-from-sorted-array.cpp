/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		int i = 0, j = 0;
		while (j < nums.size()) {
			if (nums[i] != nums[j]) {
				i++;
				nums[i] = nums[j];
			}
			j++;
		}
		return i + 1;
	}
};
// @lc code=end

