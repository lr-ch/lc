/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
			return a[1] < b[1];
		});

		int prev_end = INT_MIN, ans = 0;
		for (const auto& i : intervals) {
			int start = i[0], end = i[1];

			if (start >= prev_end)
				prev_end = end;	// no overlapping
			else
				ans++;			// overlapped
		}
		return ans;
	}
};
// @lc code=end
