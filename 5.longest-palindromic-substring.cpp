/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
	string longestPString(string &s, int begin1, int begin2) {
		while (begin1 >= 0 && begin2 < s.size()) {
			if (s[begin1] != s[begin2])
				break;
			begin1--;
			begin2++;
		}
		return s.substr(begin1 + 1, begin2 - 1 - begin1);
	}

	string& strmax(string &s1, string &s2) {
		return s1.size() > s2.size() ? s1 : s2;
	}

public:
	string longestPalindrome(string s) {
		string res;
		for (int i = 0; i < s.size(); i++) {
			string oddStr = longestPString(s, i, i);
			string evenStr = longestPString(s, i, i + 1);
			res = strmax(res, strmax(oddStr, evenStr));
		}
		return res;
	}
};
// @lc code=end

