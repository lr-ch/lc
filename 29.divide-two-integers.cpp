/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = (dividend >= 0 ^ divisor >= 0) ? -1 : 1;
		long long int quotient = 0;
		long long int dividend_ = dividend;
		long long int divisor_ = divisor;

		dividend_ = abs(dividend_);
		divisor_ = abs(divisor_);

		for (int i = 31; i >= 0; i--) {
			if ((dividend_ >> i) >= divisor_) {
				dividend_ -= (divisor_ << i);
				quotient += (1LL << i);
			}
		}

		if (quotient * sign > INT_MAX) return INT_MAX;
		if (quotient * sign < INT_MIN) return INT_MIN;

		return quotient * sign;
	}
};
// @lc code=end
