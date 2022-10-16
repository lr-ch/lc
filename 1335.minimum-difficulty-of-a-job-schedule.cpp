/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Recursive {
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
	int solve(vector<int>& jobDifficulty, int d) {
		if (d > jobDifficulty.size()) return -1;

		for (auto& m : memo) fill(m.begin(), m.end(), -1);
		return dp(jobDifficulty, 0, d);
	}
};

class Iterate {
	array<array<int, 11>, 301> memo;
public:
	int solve(vector<int>& jobDifficulty, int d) {
		if (jobDifficulty.size() < d) return -1;

		for (auto& m : memo) fill(m.begin(), m.end(), 3e6);

		/*
		 *    k - 1            1
		 * +------------+-------------+
		 * | 1 ...... j | j + 1 ... i |
		 * +------------+-------------+
		 *   dp[j][k-1]   max(jobs[j+1], jobs[j+2], ..., jobs[i])
		 */
		memo[0][0] = 0;
		for (int i = 1; i <= jobDifficulty.size(); i++) {
			for (int k = 1; k <= d; k++) {
				int max_difficulty = 0;					// track for max(jobs[j+1], jobs[j+2], ..., jobs[i])
				for (int j = i - 1; j >= k - 1; j--) {
					max_difficulty = max(max_difficulty, jobDifficulty[j]);
					memo[i][k] = min(memo[i][k], max_difficulty + memo[j][k - 1]);
				}
			}
		}
		return memo[jobDifficulty.size()][d];
	}
};

class Solution {
	Recursive recur;
	Iterate itera;
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		return itera.solve(jobDifficulty, d);
	}
};
// @lc code=end
