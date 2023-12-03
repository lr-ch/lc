/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int res = 0;
		for (int i = 0; i < points.size() - 1; i++)
			res += max(
					abs(points[i][0] - points[i + 1][0]),
					abs(points[i][1] - points[i + 1][1]));
		return res;
	}
};
// @lc code=end
