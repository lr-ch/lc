/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
public:
	int numSpecial(vector<vector<int>>& mat) {
		int R = mat.size(), C = mat[0].size();
		unordered_map<int, int> row, col;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (mat[i][j]) {
					row[i] += 1;
					col[j] += 1;
				}

		int count = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
					count++;

		return count;
	}
};
// @lc code=end
