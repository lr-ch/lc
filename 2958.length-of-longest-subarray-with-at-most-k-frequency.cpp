/*
 * @lc app=leetcode id=2958 lang=cpp
 * @lcpr version=30121
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
class Solution {
public:
	int maxSubarrayLength(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
		int left = -1, ans = 0;
		for (int right = 0; right < nums.size(); right++) {
			freq[nums[right]]++;
			while (freq[nums[right]] > k) {
				left++;
				freq[nums[left]]--;		// left is excluded from subarray [left, right)
			}
			ans = max(ans, right - left);
		}
		return ans;
	}
};
// @lc code=end
