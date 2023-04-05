/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */

// @lc code=start
class Solution {
public:
	int minimizeArrayValue(vector<int>& nums) {
		long long answer = 0, preSum = 0;

		for (int i = 0; i < nums.size(); ++i) {
			preSum += nums[i];
			answer = max(answer, (preSum + i) / (i + 1));
		}

		return answer;
	}
};
// @lc code=end
