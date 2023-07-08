/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
	array<int, 32> bitFreq;
public:
	int singleNumber(vector<int>& nums) {
		fill(bitFreq.begin(), bitFreq.end(), 0);
		for (const auto& i : nums) {
			bitset<32> n(i);
			for (int bit = 0; bit < 32; bit++)
				if (n[bit]) bitFreq[bit]++;
		}

		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			ans <<= 1;
			if (bitFreq[i] % 3)
				ans |= 1;
		}

		return ans;
	}
};
// @lc code=end
