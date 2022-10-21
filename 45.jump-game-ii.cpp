/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
	int dp(vector<int>& n, int pos) {
		if (pos >= n.size() - 1) return 0;	// reach the end

		if (memo[pos] != n.size()) return memo[pos];

		int steps = n[pos];
		for (int i = 1; i <= steps; i++) {
			int min_jumps = 1 + dp(n, pos + i);
			memo[pos] = min(memo[pos], min_jumps);
		}
		return memo[pos];
	}

	array<int, 10000> memo;
public:
	int jump(vector<int>& nums) {
		fill(memo.begin(), memo.end(), nums.size());
		return dp(nums, 0);
	}
};
// @lc code=end

