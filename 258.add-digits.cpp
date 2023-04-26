/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
	int addDigits(int num) {
		int ans = 0;
		do {
			do {
				ans += num % 10;
			} while (num /= 10);

			if (ans < 10) break;

			// reset
			num = ans;
			ans = 0;
		} while (1);

		return ans;
	}
};
// @lc code=end
