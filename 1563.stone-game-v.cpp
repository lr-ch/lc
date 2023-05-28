/*
 * @lc app=leetcode id=1563 lang=cpp
 *
 * [1563] Stone Game V
 */

// @lc code=start
class Solution {
	int dp(vector<int>& sv, int left, int right) {
		if (left >= right) return 0;

		if (memo[left][right] != -1) return memo[left][right];

		int res = 0;
		for (int mid = left + 1; mid <= right; mid++) {
			int lvalue = preSum[mid] - preSum[left];
			int rvalue = preSum[right + 1] - preSum[mid];

			if (lvalue > rvalue)
				// Bob throws left part, go on the right part
				res = max(res, rvalue + dp(sv, mid, right));
			else if (rvalue > lvalue)
				// Bob throws right part, go on the left part
				res = max(res, lvalue + dp(sv, left, mid - 1));
			else
				// if both parts are the same, try both parts equally
				res = max(res, lvalue /* or rvalue, anyway they are the same*/
								+ max(
									dp(sv, mid, right),
									dp(sv, left, mid - 1)));
		}
		return memo[left][right] = res;
	}

	vector<int> preSum;
	vector<vector<int>> memo;
public:
	int stoneGameV(vector<int>& stoneValue) {
		int n = stoneValue.size();
		preSum.resize(n + 1, 0);
		for (int i = 1; i < n + 1; i++)
			preSum[i] = preSum[i - 1] + stoneValue[i - 1];

		memo.resize(n, vector<int>(n, -1));
		return dp(stoneValue, 0, n - 1);
	}
};
// @lc code=end
