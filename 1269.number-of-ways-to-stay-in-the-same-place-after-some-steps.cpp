/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution {
	int dp(int steps, int length, int pos) {
		if (steps == 0) return pos == 0 ? 1 : 0;
		if (memo[steps][pos] != -1) return memo[steps][pos];

		int ans = 0;
		for (auto& dir : dirs) {
			if (pos + dir >= steps) continue;			// skip for it never goes back to current position

			if (pos + dir >= 0 && pos + dir < length)	// make sure the position is in the array range
				ans = (ans + dp(steps - 1, length, pos + dir) % MOD) % MOD;
		}

		return memo[steps][pos] = ans;
	}

	vector<vector<int>> memo;				// memo[i][j] := remain i steps at position j
	const vector<int> dirs = {-1, 0, 1};	// (left, stay, right)
	const int MOD = 1e9 + 7;
public:
	int numWays(int steps, int arrLen) {
		memo.assign(steps + 1, vector<int>(steps + 1, -1));
		return dp(steps, arrLen, 0);
	}
};
// @lc code=end
