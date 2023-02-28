/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
        if (n == 2) return x * x;   // for case myPow(x, 2)

        // for case n == INT_MIN
        if (n == INT_MIN) {
            return myPow(1.0 / x, 0 - (n + 1)) / x;
        }

		/*
		 *  X^n = (1 / X)^(-n)
		 */
		if (n < 0)
			return myPow(1.0 / x, 0 - n);

		/*
		 *  X^n = n % 2 ? X^(n - 1) * X : (X^(n / 2)) ^ 2
		 */
		return n % 2 ? x * myPow(x, n - 1) : myPow(myPow(x, n / 2), 2);
	}
};
// @lc code=end
