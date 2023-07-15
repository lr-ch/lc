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

class Solution {
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
// @lc code=end
