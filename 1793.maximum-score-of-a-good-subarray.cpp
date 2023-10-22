/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
class Solution {
public:
	int maximumScore(vector<int>& nums, int k) {
		int N = nums.size();
		int left = k, right = k, minVal = nums[k];

		int ans = 0;
		while (left >= 0 || right < N) {
			while (left >= 0 && nums[left] >= minVal) left--;
			while (right < N && nums[right] >= minVal) right++;

			ans = max(ans, minVal * (right - left - 1));
			minVal = max(
						left >= 0 ? nums[left] : INT_MIN,
						right < N ? nums[right] : INT_MIN
					);
		}
		return ans;
	}
};
// @lc code=end
