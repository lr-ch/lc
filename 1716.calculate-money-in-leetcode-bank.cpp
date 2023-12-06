/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
public:
	int totalMoney(int n) {
		int k = n / 7, m = n % 7;
		return 7 * ((k * (k + 1) / 2) + 3 * k) + (m * (m + 1) / 2) + m * k;
	}
};
// @lc code=end
