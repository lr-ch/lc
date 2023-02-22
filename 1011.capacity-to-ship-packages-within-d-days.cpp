/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
	int daysNeed(vector<int>& weights, int caps) {
		int days = 1, loads = 0;
		for (const auto& w : weights) {
			loads += w;
			if (loads > caps) {
				days++;
				loads = w;
			}
		}
		return days;
	}

public:
	int shipWithinDays(vector<int>& weights, int days) {
		int left = *max_element(weights.begin(), weights.end());
		int right = accumulate(weights.begin(), weights.end(), 0);

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (daysNeed(weights, mid) > days)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
// @lc code=end
