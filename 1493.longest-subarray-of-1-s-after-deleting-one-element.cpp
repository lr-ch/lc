/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int left = 0, zeros = 0, ans = 0;

		for (int right = 0; right < nums.size(); right++) {
			if (!nums[right]) zeros++;

			while (zeros > 1) {
				if (!nums[left]) zeros--;
				left++;
			}

			ans = max(ans, right - left + 1 - zeros);
		}

		// must delete at least one element, even all 1s
		return ans == nums.size() ? ans - 1 : ans;
	}
};
// @lc code=end
