/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		vector<pair<int, int>> dp(nums.size(), {1, 1});		// dp[i] = (length, count) of LIS at nums[i]

		for (int i = 0; i < nums.size(); i++) {
			auto& [length, count] = dp[i];

			for (int j = 0; j < i; j++) {
				auto& [_length, _count] = dp[j];

				// x x x j x x i
				if (nums[i] <= nums[j]) continue;	// none can do

				if (_length + 1 > length) {
					length = _length + 1;			// update length of LIS
					count = _count;					// the count of LIS should be the same
				} else if (_length + 1 == length)
					count += _count;				// different LIS path to reach nums[i]
													// e.g. [1, 3, 5, 4, 7] -> [1, 3, 4, 7] and [1, 3, 5, 7]
			}
		}
		sort(dp.begin(), dp.end(), greater<>());

		int maxLen = dp[0].first, ans = 0;
		for (const auto& [length, count] : dp)
			if (length == maxLen)
				ans += count;
			else
				break;

		return ans;
	}
};
// @lc code=end
