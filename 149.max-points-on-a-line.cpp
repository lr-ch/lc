/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class SolutionMatrix {
	/*
	 * ref. https://www.cuemath.com/geometry/area-of-triangle-in-coordinate-geometry/
	 *
	 * following determinants is the area of 3-points triangle,
	 *         | x1  y1  1 |
	 *   1/2 * | x2  y2  1 | = triangle area of (x1, y1), (x2, y2) and (x3, y3)
	 *         | x3  y3  1 |
	 * if the result is 0, means these 3 points are on the same line
	 */
	int pointsOnTheLine(long x1, long y1, long x2, long y2, int j, vector<vector<int>>& pts) {
		// start counter from 2, since points (x1, y1) and (x2, y2) already make a line
		int c = 2;
		for (int k = j + 1; k < pts.size(); k++) {
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
			for (int j = i + 1; j < count; j++) {
				long x2 = points[j][0], y2 = points[j][1];
				ans = max(ans, pointsOnTheLine(x1, y1, x2, y2, j, points));
			}
		}

		return ans;
	}
};

class SolutionHashMap {
	int gcd(int m, int n) { return n == 0 ? m : gcd(n, m % n); }

	pair<int, int> slope(int x1, int y1, int x2, int y2) {
		int dx = x2 - x1, dy = y2 - y1;

		if (0 == dx) return { x1, 0 };		// a vertial line
		if (0 == dy) return { 0, y1 };		// a horizontal line

		int _gcd = gcd(dx, dy);
		return { dx / _gcd, dy / _gcd };	// normalized (x, y)
	}

public:
	int maxPoints(vector<vector<int>>& points) {
		int count = points.size();
		int res = 0;

		for (int i = 0; i < count; i++) {
			map<pair<int, int>, int> mp;	// <slope on normalized point(x1, y1), count of points>
			int x1 = points[i][0], y1 = points[i][1];
			int repeat = 0;
			int curr = 0;
			for (int j = i + 1; j < count; j++) {
				int x2 = points[j][0], y2 = points[j][1];

				// skip repeat points
				if (x1 == x2 && y1 == y2) {
					repeat++;
					continue;
				}

				curr = max(curr, ++mp[slope(x1, y1, x2, y2)]);
			}

			// start counter from 1, since points (x1, y1) already on the line
			res = max(res, 1 + curr + repeat);
		}

		return res;
	}
};

class Solution {
	/*
	 * Accepted
	 *  35/35 cases passed (71 ms)
	 *  Your runtime beats 54 % of cpp submissions
	 *  Your memory usage beats 90.39 % of cpp submissions (7.3 MB)
	 */
	SolutionMatrix noDivide;

	/*
	 * Accepted
	 *  35/35 cases passed (27 ms)
	 *  Your runtime beats 95.94 % of cpp submissions
	 *  Your memory usage beats 66.56 % of cpp submissions (12.6 MB)
	 */
	SolutionHashMap hashMap;

public:
	int maxPoints(vector<vector<int>>& points) {
	//	return noDivide.maxPoints(points);
		return hashMap.maxPoints(points);
	}
};
// @lc code=end
