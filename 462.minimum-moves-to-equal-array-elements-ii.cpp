/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mid = nums[nums.size() / 2];
		int steps = 0;
		for (int i = 0; i < nums.size(); i++)
			steps += abs(mid - nums[i]);
		return steps;
	}
};
// @lc code=end

