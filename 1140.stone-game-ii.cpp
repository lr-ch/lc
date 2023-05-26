/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution {
	int dfs(int s, int m) {
		if (s + 2 * m >= N) return suffixSum[s];	// the last turn, player takes all

		if (memo[s][m] != -1) return memo[s][m];

		int res = 0, take = 0;
		for (int i = 1; i <= 2 * m; i++) {
			// stones player takes this turn
			take = suffixSum[s] - suffixSum[s + i];

			// player takes this turn + least left stones after the other player takes
			res = max(res, take + suffixSum[s + i] - dfs(s + i, max(i, m)));
		}
		return memo[s][m] = res;
	}

	int N;
	vector<int> suffixSum;
	vector<vector<int>> memo;
public:
	int stoneGameII(vector<int>& piles) {
		N = piles.size();
		memo.resize(N, vector<int>(N, -1));
		suffixSum = piles;
		for (int i = N - 2; i >= 0; i--)
			suffixSum[i] += suffixSum[i + 1];

		return dfs(0, 1);
	}
};
// @lc code=end
