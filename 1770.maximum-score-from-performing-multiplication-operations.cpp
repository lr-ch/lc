/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start

class Solution {
	int dp(vector<int>& n, vector<int>& m, int m_index, int left) {
		int right = N - 1 - (m_index - left);
		if (m_index == M) return 0;

		if (memo[left][m_index] > INT_MIN) return memo[left][m_index];

		int left_val = n[left] * m[m_index] + dp(n, m, m_index + 1, left + 1);
		int right_val = n[right] * m[m_index] + dp(n, m, m_index + 1, left);

		return memo[left][m_index] = max(left_val, right_val);
	}

	vector<vector<int>> memo;
	int N, M;
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		N = nums.size(), M = multipliers.size();
		memo.assign(M + 1, vector<int>(M + 1, INT_MIN));
		return dp(nums, multipliers, 0, 0);
	}
};
// @lc code=end
