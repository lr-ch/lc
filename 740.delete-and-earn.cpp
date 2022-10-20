/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class SolutionRecur {
	int dp(vector<int>& vs, int n) {
		if (n < 0) return 0;
		if (memo[n] != 0) return memo[n];

		memo[n] = max(vs[n] + dp(vs, n - 2), dp(vs, n - 1));
		return memo[n];
	}

	array<int, 10000> memo;
public:
	int deleteAndEarn(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return nums[0];
		sort(nums.begin(), nums.end());

		vector<int> sum_table(nums[n - 1], 0);
		for (auto& i : nums) sum_table[i - 1] += i;
		return dp(sum_table, sum_table.size() - 1);
	}
};

class SolutionItera {
	array<int, 10000> memo;
public:
	int deleteAndEarn(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return nums[0];

		sort(nums.begin(), nums.end());
		vector<int> sum_table(nums[n - 1], 0);
		for (auto& i : nums) sum_table[i - 1] += i;

		if (sum_table.size() < 2) return sum_table[0];

		memo[0] = sum_table[0];
		memo[1] = max(sum_table[1], memo[0]);
		for (int j = 2; j < sum_table.size(); j++)
			memo[j] = max(sum_table[j] + memo[j - 2], memo[j - 1]);

		return memo[sum_table.size() - 1];
	}
};

class Solution {
	SolutionRecur recur;
	SolutionItera itera;
public:
	int deleteAndEarn(vector<int>& nums) {
	//	return recur.deleteAndEarn(nums);
		return itera.deleteAndEarn(nums);
	}
};
// @lc code=end
