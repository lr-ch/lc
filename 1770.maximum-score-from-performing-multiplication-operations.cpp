/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start

/*
 * Accepted
 *  - 50/50 cases passed (844 ms)
 *  - Your runtime beats 29.78 % of cpp submissions
 *  - Your memory usage beats 68.36 % of cpp submissions (120 MB)
 */
class SolutionRecur {
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

/*
 * Accepted
 *  - 50/50 cases passed (344 ms)
 *  - Your runtime beats 97.2 % of cpp submissions
 *  - Your memory usage beats 71.96 % of cpp submissions (119.9 MB)
 */
class SolutionItera {
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int N = nums.size(), M = multipliers.size();
		vector<vector<int>> table(M + 1, vector<int>(M + 1, 0));

		for (int m_index = M - 1; m_index >= 0; m_index--) {
			for (int left = m_index; left >= 0; left--) {
				int right = N - 1 - (m_index - left);
				table[m_index][left] = max(
										nums[left] * multipliers[m_index] + table[m_index + 1][left + 1],
										nums[right] * multipliers[m_index] + table[m_index + 1][left]
										);
			}
		}
		return table[0][0];
	}
};

class Solution {
	SolutionRecur solRecur;
	SolutionItera solItera;
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		return solItera.maximumScore(nums, multipliers);
	}
};
// @lc code=end
