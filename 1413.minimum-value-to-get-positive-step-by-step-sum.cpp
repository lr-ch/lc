/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
	int minStartValue(vector<int>& nums) {
		int minisum = 0, totalsum = 0;
		for (auto n : nums) {
			totalsum += n;
			minisum = min(minisum, totalsum);
		}
		return -minisum + 1;
	}
};
// @lc code=end

