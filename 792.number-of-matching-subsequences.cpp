/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 *  44/52 cases passed (N/A)
	 */
/*
	int numMatchingSubseq(string s, vector<string>& words) {
		int count = 0;
		for (auto& w : words) {
			int si = 0, wi = 0;
			while (si < s.length() && wi < w.length()) {
				if (s[si] == w[wi])
					wi++;
				si++;
			}
			if (wi == w.length())
				count++;
		}
		return count;
	}
*/
	bool isSubsequence(string &s, string &w) {
		int si = 0, wi = 0;
		while (si < s.length() && wi < w.length()) {
			if (s[si] == w[wi])
				wi++;
			si++;
		}
		return wi == w.length();
	}
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		map<string, bool> memo;
		int count = 0;

		for (auto& w : words) {
			if (memo.find(w) != memo.end()) {
				if (memo[w] == true)
					count++;
				continue;
			}

			memo[w] = isSubsequence(s, w);
			if (memo[w] == true)
				count++;
		}
		return count;
	}
};
// @lc code=end

