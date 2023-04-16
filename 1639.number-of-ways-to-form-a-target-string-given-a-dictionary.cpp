/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
class SolutionTopDown {
	int dfs(int ti, int fs, string& t) {
		if (fs == 0) return ti == 0 ? 1 : 0;

		if (memo[ti][fs] != -1) return memo[ti][fs];

		memo[ti][fs] = dfs(ti, fs - 1, t) % MOD;
		if (ti > 0)
			memo[ti][fs] += (long)freq[fs - 1][t[ti - 1] - 'a'] * dfs(ti - 1, fs - 1, t) % MOD;

		return memo[ti][fs];
	}

	const long MOD = 1e9 + 7;
	vector<vector<int>> freq;
	vector<vector<long>> memo;
public:
	int numWays(vector<string>& words, string target) {
		freq.resize(words[0].size(), vector<int>(26, 0));
		for (const auto& word : words)
			for (int i = 0; i < word.length(); i++) freq[i][word[i] - 'a']++;

		memo.resize(target.length() + 1, vector<long>(words[0].size() + 1, -1));

		return dfs(target.size(), words[0].size(), target) % MOD;
	}
};

class SolutionBottomUp {
	const long MOD = 1e9 + 7;
public:
	int numWays(vector<string>& words, string target) {
		vector<vector<int>> freq(words[0].size(), vector<int>(26, 0));
		for (const auto& word : words)
			for (int i = 0; i < word.length(); i++) freq[i][word[i] - 'a']++;

		vector<vector<long>> dp(target.length() + 1, vector<long>(words[0].size() + 1));
		dp[0][0] = 1;
		for (int i = 0; i < target.length() + 1; i++)
			for (int j = 0; j < words[0].size(); j++) {
				if (i < target.length())
					dp[i + 1][j + 1] += dp[i][j] * freq[j][target[i] - 'a'] % MOD;
				dp[i][j + 1] += dp[i][j] % MOD;
			}

		return dp[target.length()][words[0].size()] % MOD;
	}
};

class SolutionCompact {
	const long MOD = 1e9 + 7;
public:
	int numWays(vector<string>& words, string target) {
		vector<vector<int>> freq(words[0].size(), vector<int>(26, 0));
		for (const auto& word : words)
			for (int i = 0; i < word.length(); i++) freq[i][word[i] - 'a']++;

		vector<long> dp(target.length() + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < words[0].length(); i++)
			for (int j = target.length() - 1; j >= 0; j--)
				dp[j + 1] += dp[j] * freq[i][target[j] - 'a'] % MOD;

		return dp[target.length()] % MOD;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 89/89 cases passed (323 ms)
	 *  - Your runtime beats 51.73 % of cpp submissions
	 *  - Your memory usage beats 17.67 % of cpp submissions (79.6 MB)
	 */
	SolutionTopDown top;

	/*
	 * Accepted
	 *  - 89/89 cases passed (362 ms)
	 *  - Your runtime beats 41.38 % of cpp submissions
	 *  - Your memory usage beats 17.67 % of cpp submissions (79.7 MB)
	 */
	SolutionBottomUp bottom;

	/*
	 * Accepted
	 *  - 89/89 cases passed (248 ms)
	 *  - Your runtime beats 67.67 % of cpp submissions
	 *  - Your memory usage beats 74.14 % of cpp submissions (28.3 MB)
	 */
	SolutionCompact compact;

public:
	int numWays(vector<string>& words, string target) {
	//	return top.numWays(words, target);
	//	return bottom.numWays(words, target);
		return compact.numWays(words, target);
	}
};
// @lc code=end
