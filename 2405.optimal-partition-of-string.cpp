/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */

// @lc code=start
class Solution {
	array<bool, 26> charSet;
public:
	int partitionString(string s) {
		int ans = 1;
		fill(charSet.begin(), charSet.end(), false);

		for (int i = 0; i < s.length(); i++) {
			if (charSet[s[i] - 'a'] == true) {
				ans++;
				fill(charSet.begin(), charSet.end(), false);
			}
			charSet[s[i] - 'a'] = true;
		}
		return ans;
	}
};
// @lc code=end
