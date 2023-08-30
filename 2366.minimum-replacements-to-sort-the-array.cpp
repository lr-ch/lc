/*
 * @lc app=leetcode id=2366 lang=cpp
 *
 * [2366] Minimum Replacements to Sort the Array
 */

// @lc code=start
class Solution {
public:
	long long minimumReplacement(vector<int>& nums) {
		long long ret = 0;

		for (int i = nums.size() - 2; i >= 0; i--) {
			// backward iteration
			int prev = nums[i + 1], curr = nums[i];

			// no ops needed
			if (curr <= prev) continue;

			// count ops needed
			long long ops = (curr + prev - 1) / prev;
			ret += ops - 1;

			// after ops, update current number
			nums[i] = curr / ops;
		}

		return ret;
	}
};
// @lc code=end
