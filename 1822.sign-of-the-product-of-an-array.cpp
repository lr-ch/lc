/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
	int arraySign(vector<int>& nums) {
		if (find(nums.begin(), nums.end(), 0) != nums.end()) return 0;
		if (count_if(nums.begin(), nums.end(), [](int i) { return i < 0; }) % 2)
			return -1;
		return 1;
	}
};
// @lc code=end
