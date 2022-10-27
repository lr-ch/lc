/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
	/*
	 * Shift m1 up-left/up-right, then count '1' in overlapped area.
	 */
	int shiftAndCount(int shiftX, int shiftY, vector<vector<int>>& m1, vector<vector<int>>& m2) {
		int toLeft = 0, toRight = 0;
		int row2 = 0;

		// count '1' in overlapped area
		for (int row1 = shiftY; row1 < m1.size(); row1++) {
			int col2 = 0;
			for (int col1 = shiftX; col1 < m1.size(); col1++) {
				if (m1[row1][col1] == 1 && m1[row1][col1] == m2[row2][col2]) toLeft++;
				if (m1[row1][col2] == 1 && m1[row1][col2] == m2[row2][col1]) toRight++;
				col2++;
			}
			row2++;
		}
		return max(toLeft, toRight);
	}

public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int ans = 0;

		for (int shiftY = 0; shiftY < img1.size(); shiftY++) {
			for (int shiftX = 0; shiftX < img1.size(); shiftX++) {
				ans = max(ans, shiftAndCount(shiftX, shiftY, img1, img2));
				ans = max(ans, shiftAndCount(shiftX, shiftY, img2, img1));
			}
		}

		return ans;
	}
};
// @lc code=end

