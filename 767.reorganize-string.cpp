/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
	string reorganizeString(string s) {
		vector<pair<int, char>> freq(26);	// (count, ch)
		for (const char& ch : s) {
			freq[ch - 'a'].first++;
			freq[ch - 'a'].second = ch;
		}
		sort(freq.begin(), freq.end(), greater<pair<int, char>>());

		string ret(s.length(), ' ');

		int i = 0;
		for (auto& [cnt, ch] : freq) {
			while (ch && cnt--) {
				ret[i] = ch;
				// check adjacent ch
				if (i > 0 && ret[i] == ret[i - 1]) return "";
				// place next ch at odd or even index
				i += 2;
				// if all even indexes are full, reset next index to odd
				if (i >= s.length()) i = 1;
			}
		}

		return ret;
	}
};
// @lc code=end
