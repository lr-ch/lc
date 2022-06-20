/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		set<string> col(words.begin(), words.end());

		// remove all suffix of every w from the set - if existed
		for (string w : words)
			for (int i = 1; i < w.length(); i++)
				col.erase(w.substr(i));

		// sum up the length of strings in the set
		int length = 0;
		for (string s : col)
			length += s.length() + 1;	// Strng Length + '#'

		return length;
	}
};
// @lc code=end
