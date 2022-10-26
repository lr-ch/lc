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

		// initialize table with a (0, -1) for prefix sum of nums[0], because we calculate
		// with the index of *nums*, nums[0] will be the index_0 in prefix_sum_table,
		// so 0 will be index_-1 in prefix_sum_table
		unordered_map<int, int> preSumTable{{0, -1}};	// <prefix sum remainder, index>
		int preSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			preSum += nums[i];
			preSum %= k;

			// the question asks for continuous subarray of size at least two
			if (preSumTable.count(preSum) && i - preSumTable[preSum] >= 2) return true;

			// don't update the index if it has value already
			// for cases like [5,0,0,0], k = 3
			if (!preSumTable.count(preSum)) preSumTable[preSum] = i;
		}
		return false;
	}
};
// @lc code=end
