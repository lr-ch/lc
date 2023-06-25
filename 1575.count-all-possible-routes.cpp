/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
class Solution {
	int dfs(vector<int>& l, int cur, int end, int fuel) {
		if (fuel < 0) return 0;

		if (memo[cur][fuel] != -1) return memo[cur][fuel];

		// if cur == end and fuel remains, we can go other cities and back later
		// but this route should be counted as 1 as well
		memo[cur][fuel] = (cur == end ? 1 : 0);
		for (int next = 0; next < l.size(); next++) {
			if (next == cur) continue;
			if (abs(l[next] - l[cur]) <= fuel)
				memo[cur][fuel] = (memo[cur][fuel] + dfs(l, next, end, fuel - abs(l[next] - l[cur])) % MOD) % MOD;
		}
		return memo[cur][fuel] % MOD;
	}

	const int MOD = 1e9 + 7;
	vector<vector<int>> memo;	// memo[i][j] : count of routes at city i with remain fuel j
public:
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		memo.resize(locations.size(), vector<int>(fuel + 1, -1));
		return dfs(locations, start, finish, fuel);
	}
};
// @lc code=end
