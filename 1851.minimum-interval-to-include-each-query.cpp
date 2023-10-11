/*
 * @lc app=leetcode id=1851 lang=cpp
 *
 * [1851] Minimum Interval to Include Each Query
 */

// @lc code=start
class Solution {
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		vector<pair<int, int>> qindex(queries.size());		// (queries, query's index)
		for (int i = 0; i < queries.size(); i++)
			qindex[i] = { queries[i], i };
		sort(qindex.begin(), qindex.end());
		sort(intervals.begin(), intervals.end());

		int i = 0;
		vector<int> ans(queries.size(), -1);
		priority_queue<
			pair<int, int>,
			vector<pair<int, int>>,
			greater<>> durq;								// (duration, right)
		for (auto& [query, index] : qindex) {
			// put valid left_i into queue (left_i <= query <= right_i)
			while (i < intervals.size() && intervals[i][0] <= query) {
				durq.push({ intervals[i][1] -intervals[i][0] + 1, intervals[i][1]});
				i++;
			}

			// discard invalid right_i
			while (!durq.empty() && query > durq.top().second)
				durq.pop();

			if (!durq.empty()) ans[index] = durq.top().first;
		}

		return ans;
	}
};
// @lc code=end
