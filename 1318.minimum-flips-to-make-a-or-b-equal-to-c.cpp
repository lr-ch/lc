/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
	int minFlips(int a, int b, int c) {
		bitset<32> _a = a, _b = b, _c = c;
		int flips = 0;
		for (int i = 0; i < 32; i++) {
			switch (_c[i]) {
				case 0 :
					if (_a[i]) flips++;
					if (_b[i]) flips++;
					break;
				case 1 :
					if ((_a[i] | _b[i]) == 0)
						flips++;
					break;
			}
		}
		return flips;
	}
};
// @lc code=end
