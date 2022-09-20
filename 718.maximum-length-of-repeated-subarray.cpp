/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size(), ans = 0;
		vector<vector<int>> mt(n1 + 1, vector<int>(n2 + 1, 0));

		for (int i = n1 - 1; i >= 0; i--) {
			for (int j = n2 - 1; j >= 0; j--) {
				if (nums1[i] == nums2[j])
					mt[i][j] = mt[i + 1][j + 1] + 1;
				if (mt[i][j] > ans)
					ans = mt[i][j];
			}
		}
		return ans;
	}
};
// @lc code=end
