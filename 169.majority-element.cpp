/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major = 0, count = 0;

		for (const auto& n : nums) {
			if (count == 0) {
				major = n;
				count = 1;
			} else if (major == n)
				count++;
			else
				count--;
		}
		return major;
	}
};
// @lc code=end
