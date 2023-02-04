/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
	array<int, 26> freqS1, freqS2;
public:
	bool checkInclusion(string s1, string s2) {
		freqS1.fill(0);
		for (char ch : s1) freqS1[ch - 'a']++;
		freqS2.fill(0);

		int left = 0, right = 0;
		while (right < s2.length()) {
			freqS2[s2[right] - 'a']++;

			if (right - left + 1 == s1.length() && freqS1 == freqS2)
				return true;

			if (right - left + 1 < s1.length()) {
				right++;
			} else {
				freqS2[s2[left] - 'a']--;
				left++;
				right++;
			}
		}
		return false;
	}
};
// @lc code=end
