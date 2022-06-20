/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<vector<int>> dp(nums.size());

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
		//	divide by itself is default
			dp[i].push_back(nums[i]);

			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0) {
					// included divided by itself, e.g. [1,2], dp[1] = dp[0] + 1
					if (dp[i].size() <= dp[j].size()) {
						dp[i] = dp[j];
						dp[i].push_back(nums[i]);
					}
				}
			}
		}
		sort(dp.begin(), dp.end(), [](const auto& v1, const auto& v2) {
			return v1.size() > v2.size();
		});
		return dp[0];
    }
};
// @lc code=end

