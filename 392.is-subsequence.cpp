/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class SolutionTwoPtr {
public:
	bool isSubsequence(string& s, string& t) {
		auto ps = s.begin(), pt = t.begin();

		while (pt != t.end() && ps != s.end()) {
			if (*ps == *pt) ps++;
			pt++;
		}

		return ps == s.end();
	}
};

class SolutionMemo {
public:
	bool isSubsequence(string& s, string& t) {
		unordered_map<char, vector<int>> char_index;		// (char, indices of char resides)
		for (int i = 0; i < t.size(); i++)
			char_index[t[i]].push_back(i);

		int i = -1;		// init for the first char
		for (const char ch : s) {
			auto iter = upper_bound(char_index[ch].begin(), char_index[ch].end(), i);

			if (iter == char_index[ch].end()) return false;	// if no more char resides after i
			i = *iter;
		}
		return true;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 19/19 cases passed (0 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 17.6 % of cpp submissions (6.6 MB)
	 */
	SolutionTwoPtr twoPtr;

	/*
	 * Accepted
	 *  - 19/19 cases passed (0 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 7.06 % of cpp submissions (7.1 MB)
	 */
	SolutionMemo memo;
public:
	bool isSubsequence(string& s, string& t) {
	//	return twoPtr.isSubsequence(s, t);
		return memo.isSubsequence(s, t);
	}
};
// @lc code=end
