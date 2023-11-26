/*
 * @lc app=leetcode id=1727 lang=cpp
 *
 * [1727] Largest Submatrix With Rearrangements
 */

// @lc code=start
class Solution {
public:
	int largestSubmatrix(vector<vector<int>>& matrix) {
		int R = matrix.size(), C = matrix[0].size();

		// pre-process
		for (int c = 0; c < C; c++)
			for (int r = 1; r < R; r++)
				if (matrix[r][c]) matrix[r][c] += matrix[r - 1][c];

		int ans = 0;
		for (int r = 0; r < R; r++) {
			sort(matrix[r].begin(), matrix[r].end(), greater<>());
			for (int c = 0; c < C; c++)
				ans = max(ans, (c + 1) * matrix[r][c]);
		}

		return ans;
	}
};
// @lc code=end
