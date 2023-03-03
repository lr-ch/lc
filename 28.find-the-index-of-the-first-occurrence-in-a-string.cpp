/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
	void getNext(string& s, vector<int>& n) {
		int i = 1, j = 0;

		while (i < s.length()) {
			if (s[i] == s[j]) {
				n[i++] = ++j;
			} else {
				if (j == 0)
					n[i++] = 0;
				else
					j = n[j - 1];
			}
		}
	}

	int KMP(string& s, string& p, vector<int>& n) {
		int i = 0, j = 0;

		while (i < s.length()) {
			if (s[i] == p[j]) {
				i++; j++;
				if (j == p.length()) return i - p.length();
			} else {
				if (j == 0) i++;
				else j = n[j - 1];
			}
		}

		return -1;
	}

public:
	int strStr(string haystack, string needle) {
		vector<int> next(needle.size());

		getNext(needle, next);
		return KMP(haystack, needle, next);
	}
};
// @lc code=end
