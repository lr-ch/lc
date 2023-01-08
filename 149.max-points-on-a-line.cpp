/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
	/*
	 * following determinants is the area of 3-points triangle,
	 *         | x1  y1  1 |
	 *   1/2 * | x2  y2  1 | = area of (x1, y1), (x2, y2) and (x3, y3)
	 *         | x3  y3  1 |
	 * if the result is 0, means these 3 points are on the same line
	 */
	int pointsOnTheLine(long x1, long y1, long x2, long y2, int i, int j, vector<vector<int>>& pts) {
		// start counter from 2, since points (x1, y1) and (x2, y2) already make a line
		int c = 2;
		for (int k = 0; k < pts.size(); k++) {
			if (k == i || k == j) continue;		// skip current (x1, y1) and (x2, y2) points
			long x3 = pts[k][0], y3 = pts[k][1];
			if (x1 * y2 + x2 * y3 + x3 * y1 - y2 * x3 - y3 * x1 - y1 * x2 == 0)
				c++;
		}
		return c;
	}

public:
	int maxPoints(vector<vector<int>>& points) {
		int count = points.size();
		if (count < 3) return count;

		int ans = 2;	// at least two points make a line

		// y = ax + b, a = (y2 - y1) / (x2 - x1) = slope, b = offset
		for (int i = 0; i < count; i++) {
			long x1 = points[i][0], y1 = points[i][1];
			for (int j = 0; j < count; j++) {
				if (j == i) continue;
				long x2 = points[j][0], y2 = points[j][1];
				ans = max(ans, pointsOnTheLine(x1, y1, x2, y2, i, j, points));
			}
		}

		return ans;
	}
};
// @lc code=end
