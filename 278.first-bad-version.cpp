/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
	int binarysearch(long double left, long double right) {
		while (left < right) {
			long double mid = (left + right) / 2;
			// look for forward for 1st bad version
			if (isBadVersion(mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
public:
	int firstBadVersion(int n) {
		// 1...n/2...n
		return binarysearch(0, n);
	}
};
// @lc code=end

