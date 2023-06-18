/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& m, int row, int col) {
		if (length[row][col]) return length[row][col];

		length[row][col] = 1;
		for (const auto& [r, c] : dirs)
			if (row + r >= 0 && row + r < M &&
				col + c >= 0 && col + c < N &&
				m[row + r][col + c] > m[row][col]) {
				length[row][col] = max(length[row][col], 1 + dfs(m, row + r, col + c));
			}
		return length[row][col];
	}

	int M, N;
	vector<vector<int>> length;	// length[x][y] => the longest increasing path length starts from (x, y)
	const vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		M = matrix.size(), N = matrix[0].size();
		length.resize(M, vector<int>(N, 0));

		int res = 0;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				res = max(res, dfs(matrix, i, j));
		return res;
	}
};
// @lc code=end
