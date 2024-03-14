/*
 * @lc app=leetcode id=2485 lang=cpp
 *
 * [2485] Find the Pivot Integer
 */

// @lc code=start
class Solution {
public:
	int pivotInteger(int n) {
		int left = 1, right = n;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int lsum = (1 + mid) * (mid - 1 + 1) / 2;
			int rsum = (mid + n) * (n - mid + 1) / 2;

			if (lsum < rsum)
				left = mid + 1;
			else if (lsum > rsum)
				right = mid - 1;
			else
				return mid;
		}
		return -1;
	}
};
// @lc code=end
