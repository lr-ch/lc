/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start
class Solution {
	bool validate(vector<int> v) {
		sort(v.begin(), v.end());
		int d = v[1] - v[0];

		for (int i = 2; i < v.size(); i++)
			if (v[i] - v[i - 1] != d) return false;
		return true;
	}

public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		vector<bool> ans;

		for (int i = 0; i < l.size(); i++)
			ans.push_back(validate(vector<int>(begin(nums) + l[i], begin(nums) + r[i] + 1)));

		return ans;
	}
};
// @lc code=end
