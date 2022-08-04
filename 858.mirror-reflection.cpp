/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

// @lc code=start
class Solution {
public:
	/*
	 * @ref: https://leetcode.com/problems/mirror-reflection/discuss/2376191/
	 */
	int mirrorReflection(int p, int q) {
		while (0 == p % 2 && 0 == q % 2) {
			p >>= 1; q >>= 1;
		}

		return 1 - p % 2 + q % 2;
	}
};
// @lc code=end
