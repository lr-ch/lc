/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
	bool valid(const string& s) {
		int left = 0, right = s.length() - 1;
		while (left < right)
			if (s[left++] != s[right--])
				return false;
		return true;
	}

	void bt(string& s, vector<string>& p, int index, int length) {
		if (length == s.length()) ans.push_back(p);
		if (index == s.length()) return;

		for (int i = 0; i + index < s.length(); i++) {
			string tmp = s.substr(index, i + 1);
			if (valid(tmp)) {
				p.push_back(tmp);
				bt(s, p, index + i + 1, length + i + 1);
				p.pop_back();
			}
		}
	}

	vector<vector<string>> ans;
public:
	vector<vector<string>> partition(string s) {
		vector<string> parts;
		bt(s, parts, 0, 0);
		return ans;
	}
};
// @lc code=end
