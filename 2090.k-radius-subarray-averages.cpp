/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		int N = nums.size();
		vector<int> ans(N, -1);

		if (2 * k + 1 > N) return ans;

		long sum = 0;
		for (int i = 0; i < 2 * k + 1; i++)
			sum += nums[i];
		ans[k] = sum / (2 * k + 1);

		for (int i = k + 1; i < N - k; i++) {
			sum -= nums[i - k - 1];
			sum += nums[k + i];
			ans[i] = sum / (2 * k + 1);
		}
		return ans;
	}
};
// @lc code=end
