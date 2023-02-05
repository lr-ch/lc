/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
	array<int, 26> freqS, freqP;
public:
	vector<int> findAnagrams(string s, string p) {
		if (p.length() > s.length()) return {};

		freqP.fill(0);
		for (const char ch : p) freqP[ch - 'a']++;
		freqS.fill(0);
		for (int i = 0; i < p.length(); i++) freqS[s[i] - 'a']++;

		vector<int> ans;
		for (int left = 0, right = p.length() - 1; right < s.length(); left++, right++) {
			if (freqP == freqS) ans.push_back(left);

			freqS[s[left] - 'a']--;
			if (right + 1 < s.length())
				freqS[s[right + 1] - 'a']++;
		}

		return ans;
	}
};
// @lc code=end
