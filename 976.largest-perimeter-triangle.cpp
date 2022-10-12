/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
class Solution {
public:
	int largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int res = 0;
		for (int i = 0; i < nums.size() - 2; i++)
			if (nums[i] + nums[i + 1] > nums[i + 2])
				res = max(res, nums[i] + nums[i + 1] + nums[i + 2]);
		return res;
	}
};
// @lc code=end

