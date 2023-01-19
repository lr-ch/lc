/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		unordered_map<int, int> freq;

		freq[0] = 1;
		long preSum = 0;
		int ans = 0, remain = 0;
		for (const auto& n : nums) {
			preSum += n;
			remain = preSum % k;
			if (remain < 0)
				remain += k;

			if (freq.count(remain))
				ans += freq[remain];

			freq[remain]++;
		}

		return ans;
	}
};
// @lc code=end
