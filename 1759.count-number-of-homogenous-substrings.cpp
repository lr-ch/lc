/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int countHomogenous(string s) {
		int ans = 1, accu = 1;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == s[i - 1])
				accu++;
			else
				accu = 1;

			ans = (ans + accu) % MOD;
		}

		return ans;
	}
};
// @lc code=end
