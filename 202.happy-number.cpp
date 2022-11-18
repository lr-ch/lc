/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
	bool isHappy(int n) {
		set<int> seen;
		int sum = -1;

		while (sum != 1 && seen.count(n) != 1) {
			seen.insert(n);
			sum = 0;

			while (n > 0) {
				int digit = n % 10;
				n /= 10;
				sum += digit * digit;
			}
			n = sum;
		}
		return sum == 1;
	}
};
// @lc code=end

