/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class SolutionHashMap {
public:
	int longestArithSeqLength(vector<int>& nums) {
		// dp[i][j] : the length of subsequence in nums[0 .. i] with difference j
		vector<unordered_map<int, int>> dp(nums.size());

		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				int diff = nums[i] - nums[j];
				dp[i][diff] = dp[j][diff] + 1;
				res = max(res, dp[i][diff]);
			}
		}
		return res + 1;
	}
};

class SolutionArray {
	array<array<int, 1001>, 1001> dp;
public:
	int longestArithSeqLength(vector<int>& nums) {
		for (auto& arr : dp) arr.fill(0);

		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				// 0 <= nums[i] <= 500, the smallest diff will be -500
				int diff = nums[i] - nums[j] + 500;

				dp[i][diff] = dp[j][diff] + 1;
				res = max(res, dp[i][diff]);
			}
		}
		return res + 1;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 63/63 cases passed (2980 ms)
	 *  - Your runtime beats 5.05 % of cpp submissions
	 *  - Your memory usage beats 5.01 % of cpp submissions (420.5 MB)
	 */
	SolutionHashMap hashMap;

	/*
	 * Accepted
	 *  - 63/63 cases passed (258 ms)
	 *  - Your runtime beats 92.26 % of cpp submissions
	 *  - Your memory usage beats 96.45 % of cpp submissions (13.9 MB)
	 */
	SolutionArray arr;
public:
	int longestArithSeqLength(vector<int>& nums) {
	//	return hashMap.longestArithSeqLength(nums);
		return arr.longestArithSeqLength(nums);
	}
};
// @lc code=end
