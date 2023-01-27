/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
	int dfs(string& s, set<string>& d, vector<int>& m, int at) {
		if (at >= s.length()) return 1;
		if (m[at] != -1) return m[at];

		for (int cut = at + 1; cut <= s.length(); cut++) {
			string tmp = s.substr(at, cut - at);
			if (d.count(tmp) && dfs(s, d, m, cut)) {
				m[at] = 1;
				return m[at];
			}
		}

		m[at] = 0;
		return m[at];
	}

public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<int> memo(s.length(), -1);
		set<string> dict(wordDict.begin(), wordDict.end());
		return dfs(s, dict, memo, 0) == 1;
	}
};
// @lc code=end
