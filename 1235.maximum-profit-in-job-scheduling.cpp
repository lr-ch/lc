/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
	struct Job {
		int start, end, profit;

		Job(int s, int e, int p) : start(s), end(e), profit(p) {}
		bool operator<(const Job& rhs) {
			return this->end < rhs.end;
		}
	};

public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		vector<Job> vj;
		for (int i = 0; i < startTime.size(); i++)
			vj.push_back(Job(startTime[i], endTime[i], profit[i]));
		sort(vj.begin(), vj.end());

		vector<pair<int, int>> dp;		// <endTime, profit>, the accumaulated profit until endTime
		dp.push_back({ -1, 0 });		// a dummy job as boundary

		/*
		 *  1   2   3   4   5   6
		 *  +---+---+---+---+---+        dp[{-1, 0}]
		 *  |-------| p=50               dp[{3, 50}]
		 *      |-------| p=10           dp[{4, 50}]
		 *          |-------| p=40       dp[{5, 90}]
		 *          |-----------| p=70   dp[{6, 120}]
		 *
		 * 1. search dp[1...j] for endTime less or equal to vj[j]'s start time
		 * 2. two choices :
		 *    a. do not select vj[j]'s job -> the profit is currently accumulated profit
		 *    b. select vj[j]'s job -> the profit is previous endTime accumulated profit + vj[j]'s profit
		 * 3. pick maximun profit and put it into dp[]
		 * 4. the last element of dp[] has the maximun profit
		 */

		for (int j = 0; j < vj.size(); j++) {
			auto iter = upper_bound(dp.begin(), dp.end(), pair<int, int>(vj[j].start, INT_MAX));
			// NOTE : here prev(iter, 1) is protected by dummy job {-1, 0}
			dp.push_back({ vj[j].end, max(dp.back().second, prev(iter, 1)->second + vj[j].profit) });
		}

		return dp[vj.size()].second;
	}
};
// @lc code=end
