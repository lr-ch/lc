/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
	int longestArithSeqLength(vector<int>& nums) {
		// dp[i][j] : the length of subsequence in nums[0 .. i] with difference j
		vector<unordered_map<int, int>> dp(nums.size());

		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				int diff = nums[i] - nums[j];
				dp[i][diff] = dp[j][diff] + 1;
				res = max(res, dp[i][diff]);
			}
		}
		return res + 1;
	}
};
// @lc code=end
