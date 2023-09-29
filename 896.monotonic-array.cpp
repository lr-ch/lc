/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
public:
	bool isMonotonic(vector<int>& nums) {
		if (nums.size() < 3) return true;

		// state > 0 -> increasing, state < 0 -> decreasing
		int pstate = nums[1] - nums[0];
		for (int i = 2; i < nums.size(); i++) {
			int cstate = nums[i] - nums[i - 1];

			if (pstate > 0 && cstate < 0) return false;
			if (pstate < 0 && cstate > 0) return false;
			if (cstate != 0) pstate = cstate;	// e.g. [1,2,2,...,2,4]
		}

		return true;
	}
};
// @lc code=end
