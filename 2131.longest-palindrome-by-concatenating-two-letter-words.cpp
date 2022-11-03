/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
	int longestPalindrome(vector<string>& words) {
		unordered_map<string, int> freq;	// (string, count of strings)
		for (auto& w : words) freq[w]++;

		vector<string> seen;
		int ans = 0;
		bool middle = false, isodd = false;
		for (auto& [str, count] : freq) {
			string revstr(str.rbegin(), str.rend());

			if (revstr != str) {
				// e.g. "ab" -> "ba"
				if (freq.count(revstr) &&
					find(seen.begin(), seen.end(), str) == seen.end() &&
					find(seen.begin(), seen.end(), revstr) == seen.end()) {
					ans += min(freq[revstr], count) * 4;	// count == freq[str]
															// a pair of "ab""ba" -> 4bytes

					seen.push_back(revstr);
					seen.push_back(str);
				}
			} else {
				// e.g. "aa" -> "aa"
				isodd = count % 2;
				int divided = count / 2;
				if (!middle && isodd) {
					ans += 2;			// "aa" in the middle -> 2 bytes
					middle = true;		// if the middle is occupied by a "aa", a "bb" will be ignored
				}
				ans += divided * 4;		// a pair of "aa""aa" -> 4 bytes
			}
		}
		return ans;
	}
};
// @lc code=end

