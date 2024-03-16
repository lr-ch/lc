/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int presum = 0, ans = 0;
		unordered_map<int, int> presum_at_i;     // (presum, index)

		for (int i = 0; i < nums.size(); i++) {
			presum += nums[i] ? 1 : -1;

			if (presum == 0)
				ans = i + 1;    // e.g. [0, 1], [0, 0, 1, 1] or [0, 0, 0, 1, 1, 1]
			else if (presum_at_i.count(presum))
				ans = max(ans, i - presum_at_i[presum]);
			else
				presum_at_i[presum] = i;
		}
		return ans;
	}
};
// @lc code=end
