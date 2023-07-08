/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
	array<int, 26> freqA, freqB;
public:
	bool buddyStrings(string s, string goal) {
		if (s.length() != goal.size()) return false;

		fill(freqA.begin(), freqA.end(), 0);
		fill(freqB.begin(), freqB.end(), 0);

		int diff = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != goal[i]) diff++;
			freqA[s[i] - 'a']++;
			freqB[goal[i] - 'a']++;
		}
		if (diff > 2) return false;

		for (int i = 0; i < 26; i++) {
			// e.g. "ab" : "ab" ==> false
			//      "aab" : "aab" ==> true
			if (diff == 0 && freqA[i] > 1)
				return true;
			if (freqA[i] != freqB[i])
				return false;
		}

		// e.g. "ab" : "ba" ==> true
		//      "ab" : "ab" ==> false
		return diff == 2;
	}
};
// @lc code=end
