/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		vector<int> memo(arr.size() + 1, 0);

		for (int i = 1; i <= arr.size(); i++) {
			int sub_sum = -1;

			for (int j = 1; j <= min(i, k); j++) {
				sub_sum = max(sub_sum, arr[i - j]);

				memo[i] = max(memo[i], memo[i - j] + sub_sum * j);
			}
		}
		return memo.back();
	}
};
// @lc code=end
