/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class SolutionIntuition {
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

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		for (int i = 0; i < strs[0].length(); i++) {
			const char ch = strs[0][i];
			for (int j = 1; j < strs.size(); j++) {
				if (i > strs[j].length())
					return strs[0].substr(0, i);
				if (ch != strs[j][i])
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};
// @lc code=end
