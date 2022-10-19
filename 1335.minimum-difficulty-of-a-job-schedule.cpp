/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Recursive {
	int dp(vector<int>& jobs, int splitIndex, int remainDays) {
		if (remainDays <= 1) return *max_element(jobs.begin() + splitIndex, jobs.end());

		if (memo[splitIndex][remainDays] != -1) return memo[splitIndex][remainDays];

		int res = INT_MAX, curr = INT_MIN;
		/*
		 * split into subproblem dp[i][k], where i is splitIndex and k is remainDays
		 *   1st day     (k-1)days
		 * +---------+---------------+
		 * | 0 ... i | i+1 ..... n-1 | n = jobs.size()
		 * +---------+---------------+
		 * dp[i][k] = max({job[0] ... job[i]}) + dp[i + 1][k - 1]
		 *
		 * e.g [6, 5, 4, 3, 2, 1], d = 2
		 *  splitIndex = 0, [6 | 5, 4, 3, 2, 1] max({6}) + max_element({5, 4, 3, 2, 1}) -> 11
		 *  splitIndex = 1, [6, 5 | 4, 3, 2, 1] max({6, 5}) + max_element({4, 3, 2, 1}) -> 10
		 *  splitIndex = 2, [6, 5, 4 | 3, 2, 1] max({6, 5, 4}) + max_element({3, 2, 1}) -> 9
		 *  splitIndex = 3, [6, 5, 4, 3 | 2, 1] max({6, 5, 4, 3}) + max_element({2, 1}) -> 8
		 *  splitIndex = 4, [6, 5, 4, 3, 2 | 1] max({6, 5, 4, 3, 2}) + max_element({1}) -> 7 (*ans
		 */
		for (int i = splitIndex; i <= jobs.size() - remainDays; i++) {
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
	void dump(vector<vector<int>>& vv) {
		for (auto& v : vv) {
			for (auto& i : v) cout << i << " ";
			cout << "\n";
		}
		cout << "\n";
	}

public:
	int solve(vector<int>& jobDifficulty, int d) {
		if (jobDifficulty.size() < d) return -1;

		vector<vector<int>> memo(jobDifficulty.size() + 1, vector<int>(d + 1, 3e6));

		memo[0][0] = 0;
		for (int i = 1; i <= jobDifficulty.size(); i++) {
			for (int k = 1; k <= d; k++) {
				int max_difficulty = 0;
				for (int j = i - 1; j >= k - 1; j--) {
					max_difficulty = max(max_difficulty, jobDifficulty[j]);
					memo[i][k] = min(memo[i][k], max_difficulty + memo[j][k - 1]);
				}
			}
		//	dump(memo);
		}
		return memo[jobDifficulty.size()][d];
	}
};

class Solution {
	Recursive recur;
	Iterate itera;
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
	//	return recur.solve(jobDifficulty, d);
		return itera.solve(jobDifficulty, d);
	}
};
// @lc code=end
