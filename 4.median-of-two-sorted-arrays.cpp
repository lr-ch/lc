/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class SolutionSort {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());
		if (nums1.size() % 2) {
			// merged.size() is odd, return the index middle
			return (double)nums1[nums1.size() / 2];
		} else {
			// merged.size() is even, return the average of middle two element
			double middle1 = (double)nums1[nums1.size() / 2 - 1];	// i.e, [1,2,3,4]
																	//         ^ ^
																	//   index 1 2
			double middle2 = (double)nums1[nums1.size() / 2];
			return (middle1 + middle2) / 2;
		}
	}
};

class SolutionBinS {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int len1 = nums1.size(), len2 = nums2.size();

		if (len1 > len2)
			return findMedianSortedArrays(nums2, nums1);

		const int half = (len1 + len2 + 1) / 2;		// the median index

		int left = 0, right = len1;
		while (left < right) {
			int med1 = left + (right - left) / 2;
			int med2 = half - med1;
			if (nums1[med1] < nums2[med2 - 1])
				left = med1 + 1;
			else
				right = med1;
		}

		// finally, med1 and med2 come out
		int med1 = left;
		int med2 = half - med1;

		int ret1 = max(
					med1 <= 0 ? INT_MIN /* picked 0 numbers from nums1 */ : nums1[med1 - 1],
					med2 <= 0 ? INT_MIN /* picked 0 numbers from nums2 */ : nums2[med2 - 1]
					);

		int ret2 = min(
					med1 >= len1 ? INT_MAX /* picked all numbers from nums1 */ : nums1[med1],
					med2 >= len2 ? INT_MAX /* picked all numbers from nums2 */ : nums2[med2]
					);

		return (len1 + len2) % 2 ? ret1 : 0.5 * (ret1 + ret2);
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 2094/2094 cases passed (40 ms)
	 *  - Your runtime beats 13.28 % of cpp submissions
	 *  - Your memory usage beats 28.9 % of cpp submissions (90 MB)
	 */
	SolutionSort combine_sort;

	/*
	 * Accepted
	 *  - 2094/2094 cases passed (15 ms)
	 *  - Your runtime beats 96.57 % of cpp submissions
	 *  - Your memory usage beats 37.84 % of cpp submissions (89.7 MB)
	 */
	SolutionBinS inplace_binary_search;
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	//	return combine_sort.findMedianSortedArrays(nums1, nums2);
		return inplace_binary_search.findMedianSortedArrays(nums1, nums2);
	}
};
// @lc code=end
