/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
	bool isCapital(char c) {
		return c >= 'A' && c <= 'Z';
	}

public:
	bool detectCapitalUse(string word) {
		if (word.length() < 2) return true;

		char ch0 = word[0];
		char ch1 = word[1];

		// "USA"
		if (isCapital(ch0) && isCapital(ch1))
			for (int i = 2; i < word.length(); i++)
				if (!isCapital(word[i])) return false;

		// "Google"
		if (isCapital(ch0) && !isCapital(ch1))
			for (int i = 2; i < word.length(); i++)
				if (isCapital(word[i])) return false;

		// "leetcode"
		if (!isCapital(ch0))
			for (int i = 1; i < word.length(); i++)
				if (isCapital(word[i])) return false;

		return true;
	}
};
// @lc code=end
