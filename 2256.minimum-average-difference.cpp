/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution {
public:
	int minimumAverageDifference(vector<int>& nums) {
		int N = nums.size();
		long sum = accumulate(nums.begin(), nums.end(), 0L);

		/*
		 * calculating prefix sum in iteration,
		 * e.g :
		 *  currSum = left part, sum - currSum = right part
		 *      [2,5,3,9,5,3]
		 *       ^ i = 0, left part = 2, right part = (sum - 2)
		 *      [2,5,3,9,5,3]
		 *         ^ i = 1, left part = 7, right part = (sum - 7)
		 *      [2,5,3,9,5,3]
		 *           ^ i = 2, left part = 10, right part = (sum - 10)
		 *
		 *  when i == N - 1, remains will be 0 and raise exception of divide by 0, yet right
		 *  part is also 0 so reset remains to any numbers will not change the result
		 */
		long currSum = 0, avgAbsDiff = 0, currMinDiff = LONG_MAX;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			currSum += nums[i];
			int remains = N - (i + 1);

			avgAbsDiff = abs(currSum / (i + 1) - (sum - currSum) / (remains ? remains : 1));

			if (avgAbsDiff < currMinDiff) {
				ans = i;
				currMinDiff = avgAbsDiff;
			}
		}
		return ans;
	}
};
// @lc code=end
