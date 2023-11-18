/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		long left = 0, right = 0, sum = 0, ans = 0;
		while (right < nums.size()) {
			sum += nums[right];

			while (sum + k < nums[right] * (right - left + 1)) {
				sum -= nums[left];
				left++;
			}

			ans = max(ans, right - left + 1);
			right++;
		}

		return ans;
	}
};
// @lc code=end
