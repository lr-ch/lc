/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
	bool isConcatable(set<char>& a, set<char>& b) {
		for (auto& ch : a) if (b.count(ch) > 0) return false;
		return true;
	}

public:
	int maxLength(vector<string>& arr) {
		vector<set<char>> freqs;
		size_t maxlen = 0;

		for (auto& str: arr) {
			set<char> freq;
			for (auto& ch : str) freq.insert(ch);

			// if there is no duplicate characters in *str*
			if (freq.size() == str.length()) freqs.push_back(freq);
		}

		// initial maximum length
		if (freqs.size() > 0)
			for (auto& fre : freqs)
				maxlen = max(maxlen, fre.size());

		vector<set<char>> concatenation(freqs.begin(), freqs.end());

		// for each *str* in arr, try to concatenate to candidate strings
		for (auto& f : freqs) {
			for (int i = 0; i < concatenation.size(); i++) {
				if (isConcatable(concatenation[i], f)) {
					// if two strings are concatenable, combine them and add this new string
					concatenation.push_back(
									set<char>(concatenation[i].begin(), concatenation[i].end()));
					concatenation.back().insert(f.begin(), f.end());
					// update answer
					maxlen = max(maxlen, concatenation.back().size());
				}
			}
		}

		return maxlen;
	}
};
// @lc code=end
