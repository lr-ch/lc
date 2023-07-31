/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class SolutionTopBottom {
	int dfs(const string_view& s1, int i, const string_view& s2, int j) {
		// if both strings are empty
		if (i == 0 && j == 0) return 0;

		if (dp[i][j] != -1) return dp[i][j];

		// if s1 is empty, delete all remain characters in s2
		if (i == 0) return dp[i][j] = accumulate(s2.begin(), s2.begin() + j, 0);
		// if s2 is empty, delete all remain characters in s1
		if (j == 0) return dp[i][j] = accumulate(s1.begin(), s1.begin() + i, 0);

		// no need to delete any characters
		if (s1[i - 1] == s2[j - 1])
			return dp[i][j] = dfs(s1, i - 1, s2, j - 1);
		else
			return dp[i][j] = min(
								dfs(s1, i - 1, s2, j) + s1[i - 1],  // delete s1[i - 1]
								dfs(s1, i, s2, j - 1) + s2[j - 1]   // delete s2[j - 1]
								);
	}

	vector<vector<int>> dp;
public:
	int minimumDeleteSum(const string_view& s1, const string_view& s2) {
		dp.resize(s1.length() + 1, vector<int>(s2.length() + 1, -1));
		return dfs(s1, s1.length(), s2, s2.length());
	}
};

class SolutionBottomTop {
public:
	int minimumDeleteSum(const string_view& s1, const string_view& s2) {
		int len1 = s1.length(), len2 = s2.length();
		if (len1 == 0) return accumulate(s2.begin(), s2.end(), 0);
		if (len2 == 0) return accumulate(s1.begin(), s1.end(), 0);

		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; i++) dp[i][0] = dp[i - 1][0] + s1[i - 1];
		for (int j = 1; j <= len2; j++) dp[0][j] = dp[0][j - 1] + s2[j - 1];

		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++)
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(
								dp[i - 1][j] + s1[i - 1],
								dp[i][j - 1] + s2[j - 1]
								);
		return dp[len1][len2];
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 93/93 cases passed (51 ms)
	 *  - Your runtime beats 60.05 % of cpp submissions
	 *  - Your memory usage beats 14.89 % of cpp submissions (15.3 MB)
	 */
	SolutionTopBottom tb;

	/*
	 * Accepted
	 *  - cases passed (37 ms)
	 *  - Your runtime beats 80.65 % of cpp submissions
	 *  - Your memory usage beats 41.16 % of cpp submissions (15.2 MB)
	 */
	SolutionBottomTop bt;
public:
	int minimumDeleteSum(const string_view& s1, const string_view& s2) {
	//	return tb.minimumDeleteSum(s1, s2);
		return bt.minimumDeleteSum(s1, s2);
	}
};
// @lc code=end
