/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
public:
	int numSubseq(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		// we cannot use standard pow() here since the strict time constraint
		vector<int> pow2(nums.size());
		// now precompute the pow(2, ) table
		pow2[0] = 1;
		for (int i = 1; i < pow2.size(); i++)
			pow2[i] = (pow2[i - 1] << 1) % MOD;

		int ans = 0, left = 0, right = nums.size() - 1;
		while (left <= right) {
			if (nums[left] + nums[right] <= target) {
			//	ans = (ans + pow(2, right - left)) % MOD;	// TLE
				ans = (ans + pow2[right - left]) % MOD;
				left++;
			} else
				right--;
		}

		return ans;
	}
};
// @lc code=end
