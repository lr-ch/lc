/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
	void makePairs(string& s, vector<pair<int, int>>& v) {
		v.clear();
		int i = 0, j = 0;
		while (i < s.length()) {
			while (s[j] == s[i]) j++;
			v.push_back({ s[i] - '0', j - i });
			i = j;
		}
	}

	void makeString(vector<pair<int, int>>& v, string &s) {
		s.clear();
		for (int i = 0; i < v.size(); i++)
			s += to_string(v[i].second) + to_string(v[i].first);
	}

public:
	string countAndSay(int n) {
		string say = "1";
		vector<pair<int, int>> digitCnt;
		while (--n) {
			makePairs(say, digitCnt);
			makeString(digitCnt, say);
		}
		return say;
	}
};
// @lc code=end
