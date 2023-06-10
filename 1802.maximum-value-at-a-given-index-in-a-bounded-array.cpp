/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
class Solution {
	long sum(long height, int n, int i) {
		long count = 0;

		// front part
		if (height > i) {
			// [height - index, ..., height - 1, height]
			count = (height + (height - i)) * (i + 1) / 2;
		} else {
			// [1, 2, ..., height - 1, height]
			count = (height + 1) * height / 2 + i - height + 1;
		}

		// back part
		if (height >= n - i) {
			// [height, height - 1, ..., height - n + 1 + i]
			count += (height + height - n + 1 + i) * (n - i) / 2;
		} else {
			// [height, height - 1, ..., 2, 1]
			count += (height + 1) * height / 2 + n - i - height;
		}

		// remove counted twice height
		return count - height;
	}

public:
	int maxValue(int n, int index, int maxSum) {
		int left = 1, right = maxSum;
		while (left < right) {
			int mid = (left + right + 1) / 2;

			if (sum(mid, n, index) > (long)maxSum)
				right = mid - 1;
			else
				left = mid;
		}
		return left;
	}
};
// @lc code=end
