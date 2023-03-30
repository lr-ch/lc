/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
	inline bool quickFilter(string a, string b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		return a == b;
	}

	unordered_map<string, bool> memo;

public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2) return true;
		if (!quickFilter(s1, s2)) return false;

		string key = s1 + "," + s2;
		if (memo.find(key) != memo.end()) return memo[key];

		for (int cut = 1; cut < s1.length(); cut++) {
			if (isScramble(s1.substr(0, cut), s2.substr(0, cut)) && isScramble(s1.substr(cut), s2.substr(cut))) {
				memo.insert({ key, true });
				return true;
			}

			// reverse scramble
			if (isScramble(s1.substr(0, cut), s2.substr(s1.size() - cut)) && isScramble(s1.substr(cut), s2.substr(0, s1.size() - cut))) {
				memo.insert({ key, true });
				return true;
			}

			memo.insert({ key, false });
		}
		return false;
	}
};
// @lc code=end
