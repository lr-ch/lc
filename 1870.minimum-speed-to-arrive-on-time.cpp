/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
class Solution {
	double computeTime(vector<int>& dist, int speed) {
		double time = accumulate(dist.begin(), dist.end() - 1, 0.0, [=](const auto& a, const auto& b) {
			return a + ceil(double(b) / double(speed));
		});
		// the dist.back() is the destination, don't need ceil()
		return time + double(dist.back()) / double(speed);
	}

public:
	int minSpeedOnTime(vector<int>& dist, double hour) {
		if (dist.size() - 1 >= hour) return -1;

		int left = 0, right = 1e7;
		while (right > left) {
			int mid = left + (right - left) / 2;
			if (hour < computeTime(dist, mid))
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
// @lc code=end
