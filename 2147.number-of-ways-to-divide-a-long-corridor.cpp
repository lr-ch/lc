/*
 * @lc app=leetcode id=2147 lang=cpp
 *
 * [2147] Number of Ways to Divide a Long Corridor
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int numberOfWays(string corridor) {
		vector<int> seat_pos;
		for (int i = 0; i < corridor.length(); i++)
			if (corridor[i] == 'S') seat_pos.push_back(i);

		if (!seat_pos.size() || seat_pos.size() % 2 != 0) return 0;

		long long ans = 1;
		for (int i = 2; i < seat_pos.size() - 1; i += 2) {
			ans *= (seat_pos[i] - seat_pos[i - 1]) % MOD;
			ans %= MOD;
		}

		return ans;
	}
};
// @lc code=end
