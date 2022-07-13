/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
	int tribonacci(int n) {
		vector<int> f = {0, 1, 1};	// f[0], f[1], f[2]
		for (int i = 3; i <= n; i++)
			f.push_back(f[i - 1] + f[i - 2] + f[i - 3]);

		return f[n];
	}
};
// @lc code=end
