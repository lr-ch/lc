/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int concatenatedBinary(int n) {
		long ans = 0;
		int shift_len = 0;
		for (int i = 1; i <= n; i++) {
			// if i is power of 2, shift length changes
			if (0 == (i & (i - 1))) shift_len++;

			ans = ((ans << shift_len) % MOD + i) % MOD;
		}
		return ans;
	}
};
// @lc code=end
