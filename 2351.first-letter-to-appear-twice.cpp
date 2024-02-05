/*
 * @lc app=leetcode id=2351 lang=cpp
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start
class Solution {
public:
	char repeatedCharacter(string s) {
		array<char, 26> freq = {0};

		for (const auto& ch : s)
			if (++freq[ch - 'a'] == 2)
				return ch;

		return 0;
	}
};
// @lc code=end
