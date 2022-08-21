/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
class Solution {
	/*
	 * try to match string a and b, ignore mismatch by '?'
	 */
	bool isMatch(string& a, string& b) {
		if (a.length() != b.length()) return false;
		for (int i = 0; i < a.length(); i++)
			if (a[i] != b[i] && a[i] != '?' && b[i] != '?')
				return false;
		return true;
	}

	bool isBlank(string& str) {
		for (char& c : str)
			if (c != '?') return false;
		return true;
	}

	void rangeErase(string &str, int begin, int length, char c) {
		fill(str.begin() + begin, str.begin() + begin + length, c);
	}

public:
	vector<int> movesToStamp(string stamp, string target) {
		vector<int> res;
		string tmp;
		bool matched = true;

		do {
			matched = false;	// reset flag

			for (int i = 0; i <= target.length() - stamp.length(); i++) {
				// extract substring for examining
				tmp = target.substr(i, stamp.length());

				if (isBlank(tmp)) continue;

				// reverse the target to blank
				if (isMatch(tmp, stamp)) {
					matched = true;
					res.push_back(i);
					rangeErase(target, i, stamp.length(), '?');
				}
			}
		} while (matched);

		if (!isBlank(target) || res.size() > 10 * target.size())
			return {};

		reverse(res.begin(), res.end());
		return res;
	}
};
// @lc code=end

