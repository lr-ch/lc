/*
 * @lc app=leetcode id=2870 lang=cpp
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */

// @lc code=start
class Solution {
public:
	int minOperations(vector<int>& nums) {
		unordered_map<int, int> freq;
		for (auto& n : nums)
			freq[n]++;

		int ans = 0;
		for (auto& [_, f] : freq) {
			if (f == 1) return -1;
			else if (f % 3 == 0) ans += f / 3;
			else if (f % 3 == 1) ans += (f / 3 + 1);	// e.g.  7 = 3 * 2 + 1 = 3 * 1 + 2 * 2 -> 3 ops
														//      10 = 3 * 3 + 1 = 3 * 2 + 2 * 2 -> 4 ops
														//		13 = 3 * 4 + 1 = 3 * 3 + 2 * 2 -> 5 ops
			else if (f % 3 == 2) ans += (f / 3 + 1);
			else if (f % 2 == 0) ans += f /2;
			else return -1;
		}
		return ans;
	}
};
// @lc code=end
