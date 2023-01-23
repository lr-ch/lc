/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
	int cut(string& s, int start) {
		if (start == s.length()) return 0;
		if (memo[start] != INT_MAX) return memo[start];

		for (int i = 0; i + start < s.length(); i++)
			if (valid[start][start + i])
				memo[start] = min(memo[start], cut(s, start + i + 1) + 1);
		return memo[start];
	}

	vector<int> memo;
	vector<vector<bool>> valid;
public:
	int minCut(string s) {
		int N = s.length();
		memo.resize(N, INT_MAX);

		valid.resize(N, vector<bool>(N, true));
		for (int base = 2; base <= N; base++)
			for (int i = 0, j = i + base - 1; j < N; i++, j++)
				valid[i][j] = (s[i] == s[j] && valid[i + 1][j - 1]);

		return cut(s, 0) - 1;
	}
};
// @lc code=end
