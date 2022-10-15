/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

// @lc code=start
class Solution {
	int dp(string& s, int i, int k) {
		if (k < 0) return s.length();		// invalid
		if (i + k >= s.length()) return 0;	// done

		if (memo[i][k] != -1) return memo[i][k];

		int res = dp(s, i + 1, k - 1);		// delete s[i]

		int encLength = 0, sameChars = 0, diffChars = 0;
		for (int j = i; j < s.length() && diffChars <= k; j++) {
			// since i == j, encLength will be at least 1
			if (s[j] == s[i]) {
				sameChars++;

				// when a -> a2, a9 -> a10, a99->a100, encLength increases
				if (sameChars <= 2 || sameChars == 10 || sameChars == 100)
					encLength++;
			} else
				diffChars++;

			res = min(res, encLength + dp(s, j + 1, k - diffChars));
		}

		memo[i][k] = res;
		return res;
	}

	// memo[i][k] => the minimun encode length if delete k characters from s[i]
	array<array<int, 101>, 101> memo;	// 1 <= s.length <= 100, 0 <= k <= s.length
public:
	int getLengthOfOptimalCompression(string s, int k) {
		for (auto &m : memo) fill(m.begin(), m.end(), -1);
		return dp(s, 0, k);
	}
};
// @lc code=end
