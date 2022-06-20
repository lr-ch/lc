/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
/*
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);

		int res = 1;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++)
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);

			res = max(res, dp[i]);
		}
		return res;
	}
*/
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;

		for (auto num : nums) {
			// find the position where the element is no bigger than num
			auto iter = lower_bound(dp.begin(), dp.end(), num);

			if (iter == dp.end())
				// not found, create a new pile
				dp.push_back(num);
			else if (num < *iter)
				// put the card on the top of pile
				*iter = num;
		}
		return dp.size();
	}
};
// @lc code=end

