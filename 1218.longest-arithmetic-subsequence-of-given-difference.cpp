/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		unordered_map<int, int> dp;
		int ans = 1;
		for (const auto& i : arr) {
			dp[i] = dp[i - difference] + 1;
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
// @lc code=end
