/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		// 1. (prefix_sum_a - prefix_sum_b) % k = 0
		// 2. (prefix_sum_a % k) - (prefix_sum_b % k) = 0
		// 3. prefix_sum_a % k = prefix_sum_b % k
		//
		// e.g. [1, 6, 15, 23, 41], k = 7
		//  --> {(1, 0), // 1 % 7 = 1, index 0
		//       (0, 1), // (1 +  6) % 7 = 0, index 1
		//       (1, 2), // (0 + 15) % 7 = 1, index 2
		//       (3, 3), // (1 + 23) % 7 = 3, index 3
		//       (2, 4)} // (3 + 41) % 7 = 2, index 4
		//  here index_2 and index_0 has the same remainder,
		//  which means prefix_sum_2 - prefix_sum_0, a.k.a, nums[1] + nums[2],
		//  can be divided by 7
		//  --> return true

		// initialize table with a (0, 0) for prefix sum of nums[0]
		unordered_map<int, int> preSumTable{{0, 0}};	// <prefix sum remainder, index>
		int preSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			preSum += nums[i];
			preSum %= k;

			if (!preSumTable.count(preSum)) preSumTable[preSum] = i + 1;
			else if (preSumTable[preSum] != i) return true;
		}
		return false;
	}
};
// @lc code=end
