/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution {
	inline double slope(vector<vector<int>>& c, int a, int b) {
		return c[b][0] - c[a][0] == 0 ? (double)INT_MIN : (c[b][1] - c[a][1]) / (c[b][0] - c[a][0]);
	}

public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		sort(coordinates.begin(), coordinates.end());

		double s = slope(coordinates, 0, 1);
		for (int i = 1; i < coordinates.size() - 1; i++)
			if (slope(coordinates, i, i + 1) != s)
				return false;
		return true;
	}
};
// @lc code=end
