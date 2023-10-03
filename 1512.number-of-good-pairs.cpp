/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
	array<int, 101> freq;
public:
	int numIdenticalPairs(vector<int>& nums) {
		freq.fill(0);
		for (const auto& n : nums) freq[n]++;

		int count = 0;
		for (const auto& f : freq)
			count += (f * (f - 1) / 2);

		return count;
	}
};
// @lc code=end
