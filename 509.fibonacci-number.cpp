/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
	int fib(int n) {
		int f_0 = 0, f_1 = 1, result;

		if (n == 0) return f_0;
		if (n == 1) return f_1;

		while (--n) {
			result = f_0 + f_1;
			f_0 = f_1;
			f_1 = result;
		}
		return result;
	}
};
// @lc code=end

