/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
class Solution {
	bool validate(int n, vector<int>& batteries, long long time) {
		long long total = 0;
		for (long long b : batteries) {
			// no matter how big a battery is, the maximun duration is limited to "time"
			total += min(b, time);
			if (total >= time * n)
				return true;
		}
		return false;
	}

public:
	long long maxRunTime(int n, vector<int>& batteries) {
		long long left = 0, right = LLONG_MAX / n;

		while (right > left) {
			long long mid = right - (right - left) / 2;

			if (validate(n, batteries, mid))
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};
// @lc code=end
