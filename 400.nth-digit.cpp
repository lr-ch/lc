/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
class Solution {
public:
	int findNthDigit(int n) {
		// 123...789       - 1 * 9 digits
		// 1011...9899     - 2 * 90 digits
		// 100101...999    - 3 * 900 digits
		// 10001001...9999 - 4 * 9000 digits
		long digit_len = 1, base = 9;
		while (n > digit_len * base) {
			n -= digit_len * base;
			digit_len += 1;		// 1 ->  2 ->   3 ...
			base *= 10;			// 9 -> 90 -> 900 ...
		}

		int start = pow(10, digit_len - 1);	// 0, 10, 100, 1000 ... -> start number
											// 1,  2,   3,    4 ... -> digit_len

		int offset = (n - 1) / digit_len;	// start from 0, so remove 0
											// e.g.  digit_len = 4, n = 5, offset is (1000 + 1)
											// e.g.2 digit_len = 3, n = 9, offset is (100 + 2)
		int index = (n - 1) % digit_len;	// same reason

		return to_string(start + offset)[index] - '0';
	}
};
// @lc code=end
