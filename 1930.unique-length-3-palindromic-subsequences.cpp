/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
	int countPalindromicSubsequence(string s) {
		bitset<26> visited, charset;
		int ans = 0;

		for (auto& ch : s) {
			if (visited[ch - 'a']) continue;
			visited.set(ch - 'a');

			charset = 0;
			int start = s.find_first_of(ch);
			int end = s.find_last_of(ch);
			for (int i = start + 1; i < end; i++)
				charset.set(s[i]- 'a');

			ans += charset.count();
		}

		return ans;
	}
};
// @lc code=end
