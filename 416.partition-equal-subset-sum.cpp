/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
	void dump(vector<vector<bool>> v) {
		for (auto vv : v) {
			for (auto i : vv) {
				cout << i << " ";
			}
			cout << "\n";
		}
	}

public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2) return false;	// if sum is odd, impossible
		sum /= 2;

		// dp[i][j] -> true or false
		// i -> how many elements picked from nums
		// j -> target number
		// if part sum of picked elements can be equal to target -> true
		// else -> false
		vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));

		// initialize base cases
		for (int i = 0; i <= nums.size(); i++)
			dp[i][0] = true;	// for cases of target is zero

		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 1; j <= sum; j++) {
				if (j - nums[i - 1] >= 0)
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	//	dump(dp);

		return dp[nums.size()][sum];
	}
};
// @lc code=end

