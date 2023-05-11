/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		// copy from 1143. Longest Common Subsequence
		int s1 = nums1.size(), s2 = nums2.size();
		vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1));

		for (int i = 1; i <= s1; i++ )
			for (int j = 1; j <= s2; j++)
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

		return dp[s1][s2];
	}
};
// @lc code=end
