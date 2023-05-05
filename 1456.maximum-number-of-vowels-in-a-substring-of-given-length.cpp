/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
	int isVowel(const char& ch) {
		return ch == 'a' || ch == 'e' || ch == 'i'
				|| ch == 'o' || ch == 'u' ? 1 : 0;
	}

public:
	int maxVowels(string s, int k) {
		int ans = 0;
		for (int i = 0; i < k; i++)
			ans += isVowel(s[i]);

		int count = ans;
		for (int j = k; j < s.length(); j++) {
			count -= isVowel(s[j - k]);
			count += isVowel(s[j]);
			ans = max(ans, count);
		}

		return ans;
	}
};
// @lc code=end
