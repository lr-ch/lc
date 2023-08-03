/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
	void bt(const string& d, int i, string& s) {
		if (i == d.length()) {
			ans.push_back(s);
			return;
		}

		for (const char& ch : codes[d[i] - '0']) {
			s.push_back(ch);
			bt(d, i + 1, s);
			s.pop_back();
		}
	}

	array<string, 10> codes = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> ans;
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};

		string tmp;
		bt(digits, 0, tmp);
		return ans;
	}
};
// @lc code=end
