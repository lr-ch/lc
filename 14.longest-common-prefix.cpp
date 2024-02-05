/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans = "";

		sort(strs.rbegin(), strs.rend());
		for (int i = 0; i < strs[0].size(); i++) {
			char ch = strs[0][i];
			for (int j = 1; j < strs.size(); j++) {
				if (i > strs[j].size())
					return ans;

				if (ch != strs[j][i])
					return ans;
			}
			ans += ch;
		}

		return ans;
	}
};
// @lc code=end
