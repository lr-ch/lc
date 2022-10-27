/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class SolutionShiftAndCount {
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

	/*
	 * e.g.  IMG1    IMG2
	 *      1 1 0   0 0 0
	 *      0 1 0   0 1 1
	 *      0 1 0   0 0 1
	 *
	 *  coord1 = { (0,0) (0,1) (1,1) (2,1) }
	 *  coord2 = { (1,1) (1,2) (2,2) }
	 *
	 *  try to align each coordination in coord1 to coord2, and track the number of
	 *  overlapped areas.
	 *
	 *  for example, align (0,0) of IMG1 to (1,1) of IMG2,
	 *                     (0,1)            (1,2)
	 *                     (1,1)            (2,2)
	 *  will get the most '1' in overlapped area
	 */
class SolutionMapping {
	void dump(vector<pair<int, int>>& v) {
		for (auto& i : v)
			cout << "(" << i.first << ", " << i.second << ") ";
		cout << "\n";
	}

	void dump2(map<pair<int, int>, int>& m) {
		for (auto& i : m)
			cout << "(" << i.first.first << "," << i.first.second << ") -> " << i.second << "\n";
		cout << "\n";
	}
public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		vector<pair<int, int>> coord1, coord2;	// coordinate (x, y) where is '1' in img1 and img2
		for (int i = 0; i < img1.size(); i++) {
			for (int j = 0; j < img1.size(); j++) {
				if (img1[i][j] == 1) coord1.push_back({ i, j });
				if (img2[i][j] == 1) coord2.push_back({ i, j });
			}
		}
	//	dump(coord1);
	//	dump(coord2);

		int ans = 0;
		map<pair<int, int>, int> map1to2;		// { (x, y), count of 1 }
		for (auto& p1 : coord1) {
			for (auto& p2 : coord2) {
				int x = p1.first - p2.first;	// x is the shift from coord1 to coord2 in x direction
				int y = p1.second - p2.second;	// y is the shift from coord1 to coord2 in y direction
				map1to2[{ x, y }]++;			// track the overlapped areas number in shift of (x, y)
				ans = max(ans, map1to2[{ x, y }]);
			}
		}
	//	dump2(map1to2);

		return ans;
	}
};

class Solution {
	SolutionShiftAndCount shiftAndCount;
	SolutionMapping mapping;
public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
	//	return shiftAndCount.largestOverlap(img1, img2);
		return mapping.largestOverlap(img1, img2);
	}
};
// @lc code=end
