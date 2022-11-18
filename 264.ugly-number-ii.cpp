/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
	int nthUglyNumber(int n) {
		if (n == 1) return 1;

		vector<int> ans(n);
		ans[0] = 1;

		int x2 = 0, x3 = 0, x5 = 0;
		for (int i = 1; i < n; i++) {
			ans[i] = min(ans[x2] * 2, min(ans[x3] * 3, ans[x5] * 5));

			if (ans[i] == ans[x2] * 2) x2++;
			if (ans[i] == ans[x3] * 3) x3++;
			if (ans[i] == ans[x5] * 5) x5++;
		}
		return ans[n - 1];
	}
};
// @lc code=end

