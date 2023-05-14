/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 */

// @lc code=start
class Solution {
	int bt(vector<int>& nums, bitset<14>& mask, int op) {
		if (op * 2 > N) return 0;

		if (memo[mask.to_ulong()] != -1) return memo[mask.to_ulong()];

		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (mask.test(i)) continue;

			mask.set(i);
			for (int j = i + 1; j < N; j++) {
				if (mask.test(j)) continue;

				mask.set(j);

				int score = (op + 1) * gcd(nums[i], nums[j]) + bt(nums, mask, op + 1);
				ret = max(ret, score);

				mask.reset(j);
			}
			mask.reset(i);
		}
		return memo[mask.to_ulong()] = ret;
	}

	int N;
	vector<int> memo;
public:
	int maxScore(vector<int>& nums) {
		N = nums.size();
		memo.resize(1 << N, -1);

		bitset<14> mask;	// 1 <= n <= 7, the max capacity is 2 * 7

		return bt(nums, mask, 0);
	}
};
// @lc code=end
