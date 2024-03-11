/*
 * @lc app=leetcode id=2540 lang=cpp
 *
 * [2540] Minimum Common Value
 */

// @lc code=start
class Solution {
public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		auto iter1 = nums1.begin(), iter2 = nums2.begin();
		while (iter1 != nums1.end() && iter2 != nums2.end()) {
			if (*iter1 == *iter2) return *iter1;

			while (iter1 != nums1.end() && *iter1 < *iter2) iter1++;
			while (iter2 != nums2.end() && *iter2 < *iter1) iter2++;
		}
		return -1;
	}
};
// @lc code=end
