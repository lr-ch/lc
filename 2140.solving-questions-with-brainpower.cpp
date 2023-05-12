/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class SolutionRecur {
	long long dfs(vector<vector<int>>& q, int i) {
		if (i >= q.size()) return 0;

		if (memo[i] != -1) return memo[i];

		return memo[i] = max(dfs(q, i + q[i][1] + 1) + q[i][0], dfs(q, i + 1));
	}

	vector<long long> memo;
public:
	long long mostPoints(vector<vector<int>>& questions) {
		memo.resize(questions.size(), -1);
		return dfs(questions, 0);
	}
};

class SolutionIter {
public:
	long long mostPoints(vector<vector<int>>& questions) {
		int N = questions.size();
		vector<long long> dp(N, 0);
		dp[N - 1] = questions.back()[0];

		for (int i = N - 2; i >= 0; i--) {
			// Add up points of the questions after skipped ones
			if (i + questions[i][1] + 1 < N)
				dp[i] = dp[i + questions[i][1] + 1];

			// select the maximun points from select/unselect
			dp[i] = max(dp[i] + questions[i][0], dp[i + 1]);
		}

		return dp[0];
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 54/54 cases passed (397 ms)
	 *  - Your runtime beats 28.09 % of cpp submissions
	 *  - Your memory usage beats 50.34 % of cpp submissions (121.6 MB)
	 */
	SolutionRecur recur;

	/*
	 * Accepted
	 *  - 54/54 cases passed (404 ms)
	 *  - Your runtime beats 20.22 % of cpp submissions
	 *  - Your memory usage beats 93.26 % of cpp submissions (115.2 MB)
	 */
	SolutionIter iter;
public:
	long long mostPoints(vector<vector<int>>& questions) {
	//	return recur.mostPoints(questions);
		return iter.mostPoints(questions);
	}
};
// @lc code=end
