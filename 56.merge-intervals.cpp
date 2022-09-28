/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
			return a[0] < b[0];
		});

		vector<vector<int>> ans;
		ans.push_back(intervals[0]);

		for (auto& i : intervals)
			if (ans.back()[1] >= i[0])
				ans.back()[1] = max(ans.back()[1], i[1]);
			else
				ans.push_back(i);
		return ans;
	}
};
// @lc code=end
