/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
	string reverseVowels(string s) {
		set<char> vowels = { 'a', 'e', 'i', 'o', 'u',
							 'A', 'E', 'I', 'O', 'U' };

		int left = 0, right = s.length() - 1;
		while (left < right) {
			while (left < s.length() && !vowels.count(s[left])) left++;
			while (right >= 0 && !vowels.count(s[right])) right--;
			if (left < right) swap(s[left++], s[right--]);
		}
		return s;
	}
};
// @lc code=end
