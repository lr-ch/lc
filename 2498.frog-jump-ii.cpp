/*
 * @lc app=leetcode id=2498 lang=cpp
 *
 * [2498] Frog Jump II
 */

// @lc code=start
class Solution {
public:
	int maxJump(vector<int>& stones) {
		int ans = stones[1] - stones[0];
		for (int i = 0; i < stones.size() - 2; i++)
			ans = max(ans, stones[i + 2] - stones[i]);
		return ans;
	}
};
// @lc code=end
