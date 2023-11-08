/*
 * @lc app=leetcode id=2849 lang=cpp
 *
 * [2849] Determine if a Cell Is Reachable at a Given Time
 */

// @lc code=start
class Solution {
public:
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
		int offset_x = abs(sx - fx), offset_y = abs(sy - fy);

		// corner case
		if (sx == fx && sy == fy && t == 1) return false;

		return max(offset_x, offset_y) <= t;
	}
};
// @lc code=end
