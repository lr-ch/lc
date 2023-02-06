/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> ans(2 * n);
		for (int i = 0, j = n; i < n; i++, j++) {
			ans[i * 2] = nums[i];
			ans[i * 2 + 1] = nums[j];
		}
		return ans;
	}
};
// @lc code=end
