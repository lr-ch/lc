/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
	/*
	 * Time Limit Exceeded
	 *  9/15 cases passed (N/A)
	 */
class SimpleDp {
	int combinationSum4(vector<int>& nums, int target) {
		if (target == 0) return 1;
		if (target < 0) return 0;

		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += combinationSum4(nums, target - nums[i]);

		return sum;
	}
};

class Solution {
	int dp(vector<int>& n, int t, vector<int>& m) {
		if (t == 0) return 1;
		if (t < 0) return 0;
		if (m[t] != -1) return m[t];

		m[t] = 0;
		for (int i = 0; i < n.size(); i++)
			m[t] += dp(n, t - n[i], m);

		return m[t];
	}

public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> memo(target + 1, -1);
		return dp(nums, target, memo);
	}
};

// @lc code=end

