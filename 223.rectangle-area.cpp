/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution {
public:
	int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		int areaA = (ay2 - ay1) * (ax2 - ax1);
		int areaB = (by2 - by1) * (bx2 - bx1);

		int overlapX = min(ax2, bx2) - max(ax1, bx1);
		int overlapY = min(ay2, by2) - max(ay1, by1);
		int areaOverlap = 0;
		if (overlapX > 0 && overlapY > 0)
			areaOverlap = overlapX * overlapY;

		return areaA + areaB - areaOverlap;
	}
};
// @lc code=end

