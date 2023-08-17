/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
	const vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		queue<pair<int, int>> q;	// (row, col)
		vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));

		for (int i = 0; i < mat.size(); i++)
			for (int j = 0; j < mat[0].size(); j++)
				if (mat[i][j] == 0) {
					q.push({i, j});
					visited[i][j] = true;
				}

		int steps = 0;
		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [row, col] = q.front(); q.pop();
				mat[row][col] = steps;

				for (const auto& [r, c] : dirs) {
					int nr = row + r, nc = col + c;

					if (nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && !visited[nr][nc]) {
						visited[nr][nc] = true;
						q.push({nr, nc});
					}
				}
			}
			steps++;
		}

		return mat;
	}
};
// @lc code=end
