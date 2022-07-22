/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int> va, vb, vc;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] < pivot)
				va.push_back(nums[i]);
			else if (nums[i] == pivot)
				vb.push_back(nums[i]);
			else
				vc.push_back(nums[i]);

		va.insert(va.end(), vb.begin(), vb.end());
		va.insert(va.end(), vc.begin(), vc.end());
		return va;
	}
};
// @lc code=end
