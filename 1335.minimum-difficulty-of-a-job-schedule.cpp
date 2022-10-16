/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
	int dp(vector<int>& jobs, int splitIndex, int remainDays) {
		// *** You have to finish at least one task every day. ***
		if (remainDays <= 1) return *max_element(jobs.begin() + splitIndex, jobs.end());

		if (memo[splitIndex][remainDays] != -1) return memo[splitIndex][remainDays];

		int res = INT_MAX, curr = INT_MIN;

		// *** You have to finish at least one task every day. ***
		for (int i = splitIndex; i < jobs.size() - remainDays + 1; i++) {
			curr = max(curr, jobs[i]);
			res = min(res, curr + dp(jobs, i + 1, remainDays - 1));
		}

		memo[splitIndex][remainDays] = res;
		return res;
	}

	// minimun difficulty cost scheduled first splitIndex jobs in remainDays
	array<array<int, 11>, 301> memo;
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		if (d > jobDifficulty.size()) return -1;

		for (auto& m : memo) fill(m.begin(), m.end(), -1);
		return dp(jobDifficulty, 0, d);
	}
};
// @lc code=end
