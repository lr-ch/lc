/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
	// <diff, count>, count of the subsequences by the difference
	typedef unordered_map<long, int> count_by_diff;

public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		// dp[i][count] -> end with nums[i], count of the subsequences by the difference
		array<count_by_diff, 1001> dp;

		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				long diff = (long)nums[i] - (long)nums[j];

				/*
				 * [1, 3, 5, 7, ...]
				 *
				 * dp[5][2] = 2 -> (1,3,5), (3,5)
				 * dp[7][2] = dp[5][2] + 1 -> (1,3,5,7), (3,5,7), (5,7)
				 * but (5,7) is not a valid subsequence, the elements is less than 3
				 * so ans += dp[5][2], not dp[7][2]
				 */
				dp[i][diff] += dp[j][diff] + 1;
				ans += dp[j][diff];
			}
		}

		return ans;
	}
};
// @lc code=end
