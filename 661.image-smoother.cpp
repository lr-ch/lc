/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
		int R = img.size(), C = img[0].size();
		vector<vector<int>> res(R, vector<int>(C));

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				int count = 0, sum = 0;

				for (int row = i - 1; row <= i + 1; row++)
					for (int col = j - 1; col <= j + 1; col++)
						if (0 <= row && row < R && 0 <= col && col < C) {
							count++;
							sum += img[row][col];
						}

				res[i][j] = sum / count;
			}
		return res;
	}
};
// @lc code=end
