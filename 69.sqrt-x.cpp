/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;

		int start = 0, end = x;
		while (start < end) {
			long long mid = start + (end - start) / 2;
			if (mid * mid == x)
				return (int)mid;
			if (mid * mid < x && (mid + 1) * (mid + 1) > x)
				return (int)mid;
			if (mid * mid > x)
				end = mid;
			if (mid * mid < x)
				start = mid;
		}
		return start;
	}
};
// @lc code=end

