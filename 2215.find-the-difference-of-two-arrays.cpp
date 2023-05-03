/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class SolutionSet {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> ans(2);

		set<int> total(nums1.begin(), nums1.end());
		total.insert(nums2.begin(), nums2.end());
		for (const auto& i : total) {
			if (find(nums2.begin(), nums2.end(), i) == nums2.end())
				ans[0].push_back(i);
			if (find(nums1.begin(), nums1.end(), i) == nums1.end())
				ans[1].push_back(i);
		}

		return ans;
	}
};

class SolutionBitSet {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		bitset<2001> bs1, bs2, bs3;
		for (int i = 0; i < min(nums1.size(), nums2.size()); i++) {
			bs1.set(nums1[i] + 1000);
			bs2.set(nums2[i] + 1000);
		}

		if (nums1.size() > nums2.size())
			for (int i = nums2.size(); i < nums1.size(); i++)
				bs1.set(nums1[i] + 1000);

		if (nums2.size() > nums1.size())
			for (int i = nums1.size(); i < nums2.size(); i++)
				bs2.set(nums2[i] + 1000);

		vector<vector<int>> ans(2);

		bs3 = bs1 ^ bs2 & bs1;
		for (int i = 0; i < 2001; i++)
			if (bs3[i]) ans[0].push_back(i - 1000);

		bs3 = bs2 ^ bs1 & bs2;
		for (int i = 0; i < 2001; i++)
			if (bs3[i]) ans[1].push_back(i - 1000);

		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 202/202 cases passed (174 ms)
	 *  - Your runtime beats 7.98 % of cpp submissions
	 *  - Your memory usage beats 67.27 % of cpp submissions (31.6 MB)
	 */
	SolutionSet bySet;

	/*
	 * Accepted
	 *  - 202/202 cases passed (32 ms)
	 *  - Your runtime beats 97.37 % of cpp submissions
	 *  - Your memory usage beats 99.1 % of cpp submissions (26.2 MB)
	 */
	SolutionBitSet byBit;
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	//	return bySet.findDifference(nums1, nums2);
		return byBit.findDifference(nums1, nums2);
	}
};
// @lc code=end
