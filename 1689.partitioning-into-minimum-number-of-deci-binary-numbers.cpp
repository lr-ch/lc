/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution {
public:
	int minPartitions(string n) {
		int minDigit = 0;
		for (char c : n)
			minDigit = max(minDigit, c - '0');
		return minDigit;
	}
};
// @lc code=end

