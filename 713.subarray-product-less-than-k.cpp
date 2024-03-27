/*
 * @lc app=leetcode id=713 lang=cpp
 * @lcpr version=30120
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		auto left = nums.begin(), right = left;
		int ans = 0;
		while (left != nums.end()) {
			int product = *right;
			while (product < k) {
				ans++;
				right++;

				if (right == nums.end())
					break;

				product *= *right;
			}

			left++;
			right = left;
		}

		return ans;
	}
};
// @lc code=end
