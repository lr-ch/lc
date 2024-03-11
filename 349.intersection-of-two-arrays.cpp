/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		auto iter1 = nums1.begin(), iter2 = nums2.begin();
		set<int> ans;
		while (iter1 != nums1.end() && iter2 != nums2.end()) {
			if (*iter1 == *iter2) {
				ans.insert(*iter1);
				iter1++;
				iter2++;
			} else if (*iter1 < *iter2) {
				iter1++;
			} else if (*iter2 < *iter1) {
				iter2++;
			}
		}

		return vector<int>(ans.begin(), ans.end());
	}
};
// @lc code=end
