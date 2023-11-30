/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
class Solution {
	unordered_map<int, int> memo;
public:
	int minimumOneBitOperations(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (memo.find(n) != memo.end()) return memo[n];

		// find leading bit of n
		string str = bitset<32>(n).to_string();
		int leading = 0;
		for (int i = 0; i < 32; i++)
			if (str[i] == '1') {
				leading = 31 - i;
				break;
			}

		return memo[n] = (1 << (leading + 1)) - 1 - minimumOneBitOperations(n ^ (1 << leading));
	}
};
// @lc code=end
