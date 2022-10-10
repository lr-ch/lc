/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
public:
	string breakPalindrome(string palindrome) {
		int len = palindrome.length();

		if (len == 1) return "";	// unable to break palindrome

		for (int i = 0; i < len / 2; i++)
			if (palindrome[i] != 'a') {
				palindrome[i] = 'a';
				return palindrome;
			}

		palindrome[len - 1] = 'b';
		return palindrome;
	}
};
// @lc code=end

