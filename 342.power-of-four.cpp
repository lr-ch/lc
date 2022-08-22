/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
	bool isPowerOfFour(int n) {
		if (n <= 0) return false;
		if ((n & (n - 1)) == 0 && (n - 1) % 3 == 0)
			return true;
		return false;
	}
};
// @lc code=end
