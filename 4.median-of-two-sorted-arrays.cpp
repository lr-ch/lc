/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
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
// @lc code=end

