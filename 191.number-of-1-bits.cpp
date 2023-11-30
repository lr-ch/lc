/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
	int hammingWeight(uint32_t n) {
		bitset<32> num = n;
		return num.count();
	}
};
// @lc code=end
