/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
class Solution {
public:
	int reductionOperations(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int ops = 0, ans = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] != nums[i])
				ops++;
			ans += ops;
		}

		return ans;
	}
};
// @lc code=end
