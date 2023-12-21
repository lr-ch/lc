/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		sort(points.begin(), points.end());
		int ans = INT_MIN;
		for (int i = 1; i < points.size(); i++)
			ans = max(ans, points[i][0] - points[i - 1][0]);
		return ans;
	}
};
// @lc code=end
