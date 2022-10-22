/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
	unordered_map<char, int> ms, mt;	// freq of chars for string s&t
public:
	string minWindow(string s, string t) {
		for (char& ch : t) mt[ch]++;

		int left = 0, right = 0;

		// when valid == mt.size(), the window contains all characters needed
		int valid = 0;

		// for record the minimum range of the window.
		// if *end* never be changed, we should return "" for no such substring
		int begin = 0, end = s.length() + 1;

		while (right < s.length()) {
			// open window wider
			char add_char = s[right];
			ms[add_char]++;
			right++;

			// increase valid counter if the characters freqs are equal
			if (mt.count(add_char) && mt[add_char] == ms[add_char]) valid++;

			// all needed characters are found, now shrink window if possible
			while (valid == mt.size()) {
				if (right - left < end - begin) {
					begin = left;
					end = right;
				}
				char del_char = s[left];
				left++;

				// decrease valid counter if the characters freqs no longer equal
				ms[del_char]--;
				if (mt.count(del_char) && mt[del_char] > ms[del_char]) valid--;
			}
		}
		return end == s.length() + 1 ? "" : s.substr(begin, end - begin);
	}
};
// @lc code=end
