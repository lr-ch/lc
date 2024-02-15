/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int> ans(nums.size());
		int pos = 0, neg = 1;
		for (const auto& n : nums)
			if (n > 0) {
				ans[pos] = n;
				pos += 2;
			} else if (n < 0) {
				ans[neg] = n;
				neg += 2;
			}
		return ans;
	}
};
// @lc code=end
