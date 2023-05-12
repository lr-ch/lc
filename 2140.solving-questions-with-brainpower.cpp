/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution {
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
// @lc code=end
