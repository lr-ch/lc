/*
 * @lc app=leetcode id=2713 lang=cpp
 *
 * [2713] Maximum Strictly Increasing Cells in a Matrix
 */

// @lc code=start
class Solution {
public:
	int maxIncreasingCells(vector<vector<int>>& matrix) {
		int M = matrix.size(), N = matrix[0].size();
		vector<tuple<int, int, int>> nums;
		vector<map<int, int>> rows(M), cols(N);     // {value, length of path}

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				nums.push_back({matrix[i][j], i, j});
		sort(nums.begin(), nums.end());

		for (int i = 0; i < M; i++) rows[i].insert({INT_MIN, 0});
		for (int j = 0; j < N; j++) cols[j].insert({INT_MIN, 0});

		int res = 1;
		for (auto& [v, r, c] : nums) {
			int len = 1;

			auto iter = rows[r].lower_bound(v);
			iter = prev(iter);
			len = max(len, iter->second + 1);

			iter = cols[c].lower_bound(v);
			iter = prev(iter);
			len = max(len, iter->second + 1);

			rows[r][v] = max(rows[r][v], len);
			cols[c][v] = max(cols[c][v], len);

			res = max(res, len);
		}

		return res;
	}
};
// @lc code=end
