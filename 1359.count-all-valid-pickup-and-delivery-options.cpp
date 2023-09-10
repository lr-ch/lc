/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int countOrders(int n) {
		/*
		 * e.g.
		 *  n = 2, sequence length is 4
		 *  P1 -+- D1 --- P2 --- D2
		 *      +- P2 -+- D1 --- D2
		 *             +- D2 --- D1
		 *  P2 -+- D2 --- P1 --- D1
		 *      +- P1 -+- D2 --- D1
		 *             +- D1 --- D2
		 */
		long long ans = 1;
		for (int i = 2; i <= n; i++)
			ans = ans * i * (2 * i - 1) % MOD;
		return ans;
	}
};
// @lc code=end
