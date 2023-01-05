/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
	struct balloon {
		int start;
		int end;
	};

public:
	int findMinArrowShots(vector<vector<int>>& points) {
		vector<balloon> balloons;
		for (auto& p : points)
			balloons.push_back({ p[0], p[1] });
		sort(balloons.begin(), balloons.end(), [](const auto& a, const auto& b) {
			return a.end < b.end;
		});

		// the first arrow
		int ans = 1, arrowX = balloons[0].end;

		// for each balloon, check whether the range covers arrowX
		for (int i = 1; i < balloons.size(); i++) {
			if (balloons[i].start <= arrowX && arrowX <= balloons[i].end)
				continue;

			// if not, move to balloon's edge and shoot a new arrow
			arrowX = balloons[i].end;
			ans++;
		}

		return ans;
	}
};
// @lc code=end
