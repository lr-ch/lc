/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class SolutionDFS {
	bool dfs(int remain) {
		if (memo[remain] != -1) return memo[remain];

		for (int i = 1; i <= sqrt(remain); i++)
			if (!dfs(remain - pow(i, 2)))	// Alice wins once, she wins
				return memo[remain] = true;

		return memo[remain] = false;
	}

	array<int, 100001> memo;
public:
	bool winnerSquareGame(int n) {
		fill(memo.begin(), memo.end(), -1);
		memo[1] = true;		// Alice starts the first turn
		return dfs(n);
	}
};

class SolutionIterate {
public:
	bool winnerSquareGame(int n) {
		bitset<100001> memo = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; pow(j, 2) <= i; j++)
				if (!memo[i - pow(j, 2)]) {
					memo.set(i);
					break;
				}

		return memo[n] == 1;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 72/72 cases passed (102 ms)
	 *  - Your runtime beats 59.61 % of cpp submissions
	 *  - Your memory usage beats 50.98 % of cpp submissions (12.2 MB)
	 */
	SolutionDFS dfs;

	/*
	 * Accepted
	 *  - 72/72 cases passed (106 ms)
	 *  - Your runtime beats 56.68 % of cpp submissions
	 *  - Your memory usage beats 91.37 % of cpp submissions (6.3 MB)
	 */
	SolutionIterate iterate;
public:
	bool winnerSquareGame(int n) {
	//	return dfs.winnerSquareGame(n);
		return iterate.winnerSquareGame(n);
	}
};
// @lc code=end
