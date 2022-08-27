/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> preSum(m + 1, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				preSum[i + 1][j] = preSum[i][j] + matrix[i][j];

		int ans = INT_MIN;
		for (int r1 = 0; r1 < m; r1++)
			for (int r2 = r1 + 1; r2 <= m; r2++)
				for (int c1 = 0; c1 < n; c1++) {
					int val = 0;
					for (int c2 = c1; c2 < n; c2++) {
						val += preSum[r2][c2] - preSum[r1][c2];

						if (val < k) {
							ans = max(ans, val);
						} else if (val == k) {
							return k;
						}
					}
				}

		return ans;
	}
};
// @lc code=end
