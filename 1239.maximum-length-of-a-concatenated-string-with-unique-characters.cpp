/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class SolutionSet {
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

class Solution {
public:
	int maxLength(vector<string>& arr) {
		vector<bitset<26>> unibits;

		for (auto& str : arr) {
			bitset<26> tmp;
			for (auto& ch : str) tmp.set(ch - 'a');

			// if there is no duplicate characters in *str*
			if (str.length() == tmp.count()) unibits.push_back(tmp);
		}

		vector<bitset<26>> concat(1, 0);
		size_t maxlen = 0;
		for (auto& bits : unibits) {
			for (int i = 0; i < concat.size(); i++) {
				if ((concat[i] & bits).none()) {
					concat.push_back(bits | concat[i]);
					maxlen = max(concat.back().count(), maxlen);
				}
			}
		}

		return maxlen;
	}
};
// @lc code=end
