/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
	// try to match s1[...i] and s2[...j] to s3[...(i + j)]
	bool match(string& s1, int i, string& s2, int j, string& s3,
				vector<vector<int>>& dp) {
		// s3[....(i + j)] all matched!
		if (i + j == s3.length()) return true;

		// if calculated, return result
		if (dp[i][j] != INT_MIN) return dp[i][j] == 1 ? true : false;

		bool status = false;
		// if s1[...i] matched s3[...(i + j)], continue trying...
		if (i < s1.length() && s1[i] == s3[i + j])
			status = match(s1, i + 1, s2, j, s3, dp);

		// if s1 failed, try s2...
		// if s2[...j] matched s3[...(i + j)], continue trying...
		if (j < s2.length() && s2[j] == s3[i + j])
		// a corner case: s1 = "aabc", s2 = "abad", s3 = "aabcabad"
		//	status = match(s1, i, s2, j + 1, s3, dp);
			status = status || match(s1, i, s2, j + 1, s3, dp);

		// both failed, record it and return false;
		dp[i][j] = (status == true ? 1 : 0);
		return status;
	}

public:
	bool isInterleave(string s1, string s2, string s3) {
		int length1 = s1.length(), length2 = s2.length();
		if (length1 + length2 != s3.length()) return false;

		// dp[i][j] = INT_MIN -> Not calculated
		//          = 1       -> Matched
		//          = 0       -> Unmatched
		vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, INT_MIN));

		return match(s1, 0, s2, 0, s3, dp);
	}
};
// @lc code=end

