/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
class SolutionPOC {
	/*
	 * Time Limit Exceeded
	 *	- 64/67 cases passed (N/A)
	 */
	int dfs(vector<vector<int>>& e, int k, int cur) {
		if (k == 0 || cur == e.size()) return 0;

		/*
		 * if we take this event, the next event's start time should be larger than current event's end time
		 */
		auto next = upper_bound(e.begin() + cur, e.end(), vector<int>{e[cur][1] + 1, 0, 0});
		return max(
				e[cur][2] + dfs(e, k - 1, distance(e.begin(), next)),	// take this event
				dfs(e, k, cur + 1));									// skip this event
	}

public:
	int maxValue(vector<vector<int>>& events, int k) {
		sort(events.begin(), events.end());
		return dfs(events, k, 0);
	}
};

class SolutionBinSearchDfs {
	int dfs(vector<vector<int>>& e, int k, int cur) {
		if (k == 0 || cur == e.size()) return 0;

		if (memo[k][cur] != -1) return memo[k][cur];

		/*
		 * if we take this event, the next event's start time should be larger than current event's end time
		 */
		auto next = upper_bound(e.begin() + cur, e.end(), vector<int>{e[cur][1] + 1, 0, 0});
		return memo[k][cur] = max(
								e[cur][2] + dfs(e, k - 1, distance(e.begin(), next)),	// take this event
								dfs(e, k, cur + 1));									// skip this event
	}

	vector<vector<int>> memo;
public:
	int maxValue(vector<vector<int>>& events, int k) {
		sort(events.begin(), events.end());

		memo.resize(k + 1, vector<int>(events.size(), -1));
		return dfs(events, k, 0);
	}
};

class SolutionCompareEndTime {
	int dfs(vector<vector<int>>& e, int k, int cur, int end) {
		if (k == 0 || cur == e.size()) return 0;

		// If current start time is less than previous end time then skip this event
		if (e[cur][0] <= end) return dfs(e, k, cur + 1, end);

		if (memo[k][cur] != -1) return memo[k][cur];

		return memo[k][cur] = max(
								e[cur][2] + dfs(e, k - 1, cur + 1, e[cur][1]),	// take this event
								dfs(e, k, cur + 1, end));						// skip this event
	}

	vector<vector<int>> memo;
public:
	int maxValue(vector<vector<int>>& events, int k) {
		sort(events.begin(), events.end());

		memo.resize(k + 1, vector<int>(events.size(), -1));
		return dfs(events, k, 0, 0);
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 67/67 cases passed (346 ms)
	 *  - Your runtime beats 55.45 % of cpp submissions
	 *  - Your memory usage beats 8.05 % of cpp submissions (106.9 MB)
	 */
	SolutionBinSearchDfs bs_dfs;
	/*
	 * Accepted
	 *  - 67/67 cases passed (272 ms)
	 *  - Your runtime beats 98.26 % of cpp submissions
	 *  - Your memory usage beats 83.1 % of cpp submissions (67.2 MB)
	 */
	SolutionCompareEndTime comp_end;
public:
	int maxValue(vector<vector<int>>& events, int k) {
	//	return bs_dfs.maxValue(events, k);
		return comp_end.maxValue(events, k);
	}
};
// @lc code=end
