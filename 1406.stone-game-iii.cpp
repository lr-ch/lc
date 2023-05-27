/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
	int dfs(vector<int>& v, int i) {
		if (i >= N) return 0;
		if (memo[i] != INT_MIN) return memo[i];

		for (int j = 0, sum = 0; j < 3 && i + j < N; j++) {
			sum += v[i + j];

			// player can get maximun scores at i-th piles =
			//  -> current scores
			//	-> current scores of selection of [1 .. 3] piles
			//      - the oppsite can get maximun scores after i + [1 .. 3] piles)
			memo[i] = max(memo[i], sum - dfs(v, i + j + 1));
		}
		return memo[i];
	}

	vector<int> memo;	// memo[i] -> the maximun score player can get at i-th piles
	int N;
public:
	string stoneGameIII(vector<int>& stoneValue) {
		N = stoneValue.size();
		memo.resize(N, INT_MIN);
		dfs(stoneValue, 0);

		return memo[0] > 0 ? "Alice" : memo[0] < 0 ? "Bob" : "Tie";
	}
};
// @lc code=end
