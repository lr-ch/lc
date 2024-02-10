/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
	bool checkPalindrome(string& s, int l, int r) {
		while (l < r)
			if (s[l++] != s[r--]) return false;
		return true;
	}

public:
	int countSubstrings(string s) {
		int ans = 0;

		for (int l = 0; l < s.length(); l++)
			for (int r = l; r < s.length(); r++)
				if (checkPalindrome(s, l, r))
					ans++;
		return ans;
	}
};
// @lc code=end
