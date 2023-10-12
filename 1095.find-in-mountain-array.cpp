/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
	pair<int, int> findPeak(int left, int right, MountainArray &m) {
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (m.get(mid) < m.get(mid + 1))
				left = mid + 1;
			else
				right = mid;
		}
		return { left, m.get(left) };	// (index, height) of peak
	}

	int findAscending(int left, int right, int target, MountainArray &m) {
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (m.get(mid) < target)
				left = mid + 1;
			else
				right = mid;
		}
		return m.get(left) == target ? left : -1;
	}

	int findDescending(int left, int right, int target, MountainArray &m) {
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (m.get(mid) > target)
				left = mid + 1;
			else
				right = mid;
		}
		return m.get(left) == target ? left : -1;
	}

	int findTarget(int left, int right, int target, bool ascend, MountainArray &m) {
		while (left < right) {
			int mid = left + (right - left) / 2;
			if ((ascend && m.get(mid) < target) || (!ascend && m.get(mid) > target))
				left = mid + 1;
			else
				right = mid;
		}
		return m.get(left) == target ? left : -1;
	}

public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int N = mountainArr.length();
		pair<int, int> peak = findPeak(0, N - 1, mountainArr);

		// is peak target?
		if (peak.second == target) return peak.first;

		// search in ascending slope
		int ans = findAscending(0, peak.first - 1, target, mountainArr);
	//	int ans = findTarget(0, peak.first - 1, target, true, mountainArr);
		if (ans != -1) return ans;

		// search in descending slope
		ans = findDescending(peak.first + 1, N - 1, target, mountainArr);
	//	ans = findTarget(peak.first + 1, N - 1, target, false, mountainArr);
		return ans;
	}
};
// @lc code=end
