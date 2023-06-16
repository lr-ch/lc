/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */

// @lc code=start
class Solution {
	int dfs(vector<int>& nums) {
		// obviously when nums contains less/equal than two numbers, e.g. {1, 2}, there is only one way
		if (nums.size() <= 2) return 1;

		vector<int> left, right;

		for (int i = 1; i < nums.size(); i++)
			if (nums[i] < nums[0])
				left.push_back(nums[i]);
			else
				right.push_back(nums[i]);

		// Combination of {total, left tree size(or right tree size)} *
		//   ways of left tree *
		//   ways of right tree
		return (((table[nums.size() - 1][left.size()]) * (dfs(left) % MOD) % MOD) * dfs(right) % MOD) % MOD;
	}

	vector<vector<long>> table;		// a pascal triangle for memo of combination numbers
	const long MOD = 1e9 + 7;
public:
	int numOfWays(vector<int>& nums) {
		table.resize(nums.size() + 1);
		for (int i = 0; i < nums.size() + 1; i++) {
			table[i].resize(i + 1, 1);
			for (int j = 1; j < i; j++)
				table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
		}

		return (dfs(nums) - 1) % MOD;
	}
};
// @lc code=end
