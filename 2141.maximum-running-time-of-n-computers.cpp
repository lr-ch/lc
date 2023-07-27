/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
class SolutionSort {
public:
	long long maxRunTime(int n, vector<int>& batteries) {
		sort(batteries.begin(), batteries.end(), greater<>());
		long long total = accumulate(batteries.begin(), batteries.end(), 0LL);

		for (long long b : batteries) {
			long long avg = total / n;

			if (b <= avg) break;

			total -= b;
			n--;
		}

		return total / n;
	}
};

class SolutionBinSearch {
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

class Solution {
	/*
	 * Accepted
	 *  - 52/52 cases passed (97 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 98.56 % of cpp submissions (55.7 MB)
	 */
	SolutionSort sort;

	/*
	 * Accepted
     *  - 52/52 cases passed (133 ms)
     *  - Your runtime beats 99.64 % of cpp submissions
     *  - Your memory usage beats 71.58 % of cpp submissions (55.8 MB)
	 */
	SolutionBinSearch bin;
public:
	long long maxRunTime(int n, vector<int>& batteries) {
		return sort.maxRunTime(n, batteries);
	//	return bin.maxRunTime(n, batteries);
	}
};
// @lc code=end
