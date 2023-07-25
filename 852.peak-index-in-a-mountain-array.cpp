/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left = 0, right = arr.size() - 1, mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (arr[mid] > arr[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}
};
// @lc code=end
