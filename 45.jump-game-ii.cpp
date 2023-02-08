/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class SolutionDFS {
	int dp(vector<int>& n, int pos) {
		if (pos >= n.size() - 1) return 0;	// reach the end

		if (memo[pos] != n.size()) return memo[pos];

		int steps = n[pos];
		for (int i = 1; i <= steps; i++) {
			int min_jumps = 1 + dp(n, pos + i);
			memo[pos] = min(memo[pos], min_jumps);
		}
		return memo[pos];
	}

	array<int, 10000> memo;
public:
	int jump(vector<int>& nums) {
		fill(memo.begin(), memo.end(), nums.size());
		return dp(nums, 0);
	}
};

class SolutionGreedy {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;

		int maxDistance = nums[0], steps = nums[0], jumps = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (i == nums.size() - 1) return jumps;

			maxDistance = max(maxDistance, i + nums[i]);
			steps--;
			if (!steps) {
				jumps++;
				steps = maxDistance - i;
			}
		}

		return -1;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 109/109 cases passed (519 ms)
	 *  - Your runtime beats 20.59 % of cpp submissions
	 *  - Your memory usage beats 17.45 % of cpp submissions (17.6 MB)
	 */
	SolutionDFS dfs;

	/*
	 * Accepted
	 *  - 109/109 cases passed (12 ms)
	 *  - Your runtime beats 92.2 % of cpp submissions
	 *  - Your memory usage beats 56.17 % of cpp submissions (16.6 MB)
	 */
	SolutionGreedy greedy;

public:
	int jump(vector<int>& nums) {
	//	return dfs.jump(nums);
		return greedy.jump(nums);
	}
};
// @lc code=end
