/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start
class Solution {
public:
	int bulbSwitch(int n) {
		/*
		 *      1 2 3 4 5 6 7 8 9
		 * r.1  O O O O O O O O O
		 * r.2  O X O X O X O X O  (2, 4, 6, 8 => X)
		 * r.3  O X X X O O O X X  (3, 9 => X, 6 => O)
		 * r.4  O X X O O O O O X  (4 => O, 8 => O)
		 * r.5  O X X O X O O O X  (5 => X)
		 *              .          (6 => X)
		 *              .          (7 => X)
		 *              .          (8 => X)
		 *              .          (9 => O) ans. 3(1, 4, 9)
		 *
		 * Observation: when y^2 <= n, y have chances to switch 2x times
		 *  i.e. 4 switched at r.2 and r.4
		 *       9 swtiched at r.3 and r.9
		 *  So the number of bulbs that are on is count(y)
		 */
		return sqrt(n);
	}
};
// @lc code=end
