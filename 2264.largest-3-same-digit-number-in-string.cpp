/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
class Solution {
public:
	string largestGoodInteger(string num) {
		char n = 0;
		for (int i = 0; i < num.size() - 2; i++)
			if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
				n = max(n, num[i]);
		return n == 0 ? "" : string(3, n);
	}
};
// @lc code=end
