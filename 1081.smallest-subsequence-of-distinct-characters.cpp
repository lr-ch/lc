/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
class Solution {
public:
	string smallestSubsequence(string s) {
		vector<int> freq(26, 0);
		for (const auto& ch : s) freq[ch - 'a']++;

		string ret;
		for (const auto& ch : s) {
			freq[ch - 'a']--;

			if (ret.find(ch) != string::npos) continue;

			while (!ret.empty() && ret.back() > ch && freq[ret.back() - 'a'])
				ret.pop_back();

			ret += ch;
		}
		return ret;
	}
};
// @lc code=end
