/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution2D {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		// dp[i][j] := the max dot product in sub-seq of nums1[0..i] and nums2[0..j]
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN / 2));

		for (int i = 1; i <= nums1.size(); i++)
			for (int j = 1; j <= nums2.size(); j++) {
				dp[i][j] = max({
							dp[i - 1][j],	// case.1 skip nums1[i]
							dp[i][j - 1],	// case.2 skip nums2[j]
							// case.3a dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1]
							// case.3b if dp[i - 1][j - 1] <= 0,
							//         restart from nums1[i - 1] * nums2[j - 1]
							max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]
							});
			}
		return dp[nums1.size()][nums2.size()];
	}
};

class SolutionExp {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		vector<int> curr(nums2.size() + 1, INT_MIN / 2), prev = curr;

		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				int dot_product = nums1[i - 1] * nums2[j - 1];
				int case1 = prev[j], case2 = curr[j - 1],
					case3a = prev[j - 1] + dot_product,
					case3b = 0 + dot_product;
				curr[j] = max({ case1, case2, case3a, case3b });
			}
			swap(curr, prev);
		}
		return prev.back();
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 62/62 cases passed (21 ms)
	 *  - Your runtime beats 82.52 % of cpp submissions
	 *  - Your memory usage beats 98.2 % of cpp submissions (9.9 MB)
	 */
	Solution2D s2d;

	/*
	 * Accepted
	 *  - 62/62 cases passed (25 ms)
	 *  - Your runtime beats 76.86 % of cpp submissions
	 *  - Your memory usage beats 99.23 % of cpp submissions (9.8 MB)
	 */
	SolutionExp exp;
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
	//	return s2d.maxDotProduct(nums1, nums2);
		return exp.maxDotProduct(nums1, nums2);
	}
};
// @lc code=end
