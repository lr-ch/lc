/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		unordered_map<int, int> preSumIndex;			// (prefix sum, index)
		int preSum = 0;
		for (int i = 0; i < nums.size(); i++)
			preSumIndex[preSum += nums[i]] = i + 1;		// count from 1 for convenience
		size_t ans = (preSumIndex.count(x) ? preSumIndex[x] : INT_MAX);

		int suffSum = 0;
		for (int j = nums.size() - 1; j >= 0; j--) {
			suffSum += nums[j];
			size_t target = x - suffSum;

			// if some prefix sum + suffix sum == x && their indices are not overlapped
			if (preSumIndex.count(target) && preSumIndex[target] < j) {
				ans = min(
						ans,
						preSumIndex[target] /* front operations */ +
						nums.size() - j /* back operations */);
			} else if (suffSum == x)
				ans = min(ans, nums.size() - j);
		}
		return ans == INT_MAX ? -1 : ans;
	}
};
// @lc code=end
