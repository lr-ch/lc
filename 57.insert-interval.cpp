/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		for (const auto& it : intervals) {
			if (it[1] < newInterval[0]) {
			// if current_intervals.end < new_intervals.start
				res.push_back(it);
			} else if (it[0] > newInterval[1]) {
			// if current_intervals.start > new_intervals.end
				res.push_back(newInterval);
				newInterval = it;
			} else {
			// if (current_intervals.end > new_intervals.start) && (current_intervals.start < new_intervals.end)
				newInterval = { min(it[0], newInterval[0]), max(it[1], newInterval[1]) };
			}
		}
		res.push_back(newInterval);

		return res;
	}
};
// @lc code=end
