/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index_tail = nums1.size() - 1;

		while (m != 0 && n != 0) {
			if (nums1[m - 1] > nums2[n - 1]) {
				nums1[index_tail] = nums1[m - 1];
				m--;
			} else {
				nums1[index_tail] = nums2[n - 1];
				n--;
			}
			index_tail--;
		}

		if (m > 0)
			for (; m > 0 && index_tail >= 0; m--, index_tail--)
				nums1[index_tail] = nums1[m - 1];
		if (n > 0)
			for (; n > 0 && index_tail >= 0; n--, index_tail--)
				nums1[index_tail] = nums2[n - 1];
	}
};
// @lc code=end

