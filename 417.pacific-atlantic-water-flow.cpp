/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
	int m, n;

	void flow(vector<vector<int>>& h, vector<vector<bool>>& t, int row, int col) {
		if(row < 0 || row > m - 1 || col < 0 || col > n - 1) return;
		if (!t[row][col]) {
			t[row][col] = true;

			if (row - 1 >= 0 && h[row][col] <= h[row - 1][col]) flow(h, t, row - 1, col);
			if (col - 1 >= 0 && h[row][col] <= h[row][col - 1]) flow(h, t, row, col - 1);
			if (row + 1 < m && h[row][col] <= h[row + 1][col]) flow(h, t, row + 1, col);
			if (col + 1 < n && h[row][col] <= h[row][col + 1]) flow(h, t, row, col + 1);
		}
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		m = heights.size(), n = heights[0].size();
		vector<vector<bool>> toPac(m, vector<bool>(n, false));
		vector<vector<bool>> toAtl(m, vector<bool>(n, false));
		vector<vector<int>> ans;

		for (int p = 0; p < m; p++)
			for (int q = 0; q < n; q++) {
				if ((p == m - 1 || q == n - 1) && !toAtl[p][q])
					flow(heights, toAtl, p, q);
				if ((p == 0 || q == 0) && !toPac[p][q])
					flow(heights, toPac, p, q);
			}

		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				if (toPac[x][y] && toAtl[x][y])
					ans.push_back({ x, y });

		return ans;
	}
};
// @lc code=end
