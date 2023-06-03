/*
 * @lc app=leetcode id=1690 lang=cpp
 *
 * [1690] Stone Game VII
 */

// @lc code=start
class Solution {
	int dfs(vector<int>& s, int left, int right, int sum) {
		if (left >= right) return 0;

		if (memo[left][right]) return memo[left][right];

		return memo[left][right] =
				max(
					sum - s[left] - dfs(s, left + 1, right, sum - s[left]),
					sum - s[right] - dfs(s, left, right - 1, sum - s[right])
				);
	}

	vector<vector<int>> memo;
public:
	int stoneGameVII(vector<int>& stones) {
		memo.resize(stones.size(), vector<int>(stones.size()));
		return dfs(stones, 0, stones.size() - 1, accumulate(begin(stones), end(stones), 0));
	}
};
// @lc code=end
