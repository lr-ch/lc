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
			// e.g.
			//      -----+------+--------+-------+-----
			//           ^      ^        ^       ^
			//               cur.end  new.start
				res.push_back(it);
			} else if (it[0] > newInterval[1]) {
			// if current_intervals.start > new_intervals.end
			// e.g.
			//      -----+------+---------+------+-----
			//           ^      ^         ^      ^
			//               new.end  curr.start
				res.push_back(newInterval);
				newInterval = it;
			} else {
			// if current_intervals.end > new_intervals.start && current_intervals.start < new_intervals.end
			// e.g.
			//      -----+------+---------+------+-----
			//           ^      ^         ^      ^
			//              curr.start new.end
			// or
			//      -----+------+-----------+-----+----
			//           ^      ^           ^     ^
			//               new.start  curr.end
				newInterval = { min(it[0], newInterval[0]), max(it[1], newInterval[1]) };
			}
		}
		res.push_back(newInterval);

		return res;
	}
};
// @lc code=end
