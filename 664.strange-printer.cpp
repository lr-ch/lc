/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
class Solution {
	// return the minimun steps to print s{left .. right}
	int dp(string& s, int left, int right) {
		if (left > right) return 0;
		if (memo[left][right] != -1) return memo[left][right];

		int ans = dp(s, left, right - 1) + 1;   // default case, print every character each time
												// e.g. "abcdefg"
		// now try to find lesser steps
		for (int mid = left; mid < right; mid++)
			// try to find a character the same as the end one, save one time print
			// e.g. "abcba", s[left] is 'a' and s[right] is 'a' as well
			//  -> can be printed as "aaaaa" plus "bcb"
			if (s[mid] == s[right])
				ans = min(ans, dp(s, left, mid) + dp(s, mid + 1, right - 1));

		return memo[left][right] = ans;
	}

	vector<vector<int>> memo;
public:
	int strangePrinter(string& s) {
		memo.resize(s.length(), vector<int>(s.length(), -1));
		return dp(s, 0, s.length() - 1);
	}
};
// @lc code=end
