/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution {
public:
	int numFactoredBinaryTrees(vector<int>& arr) {
		const long mod = 1000000007;
		/*
		 * dp[A] = number of trees with root value 'A'
		 *  if (A = B * C)
		 *  then (dp[A] = dp[B] * dp[C])
		 *  example:
		 *    [2,4,8]
		 *    dp[8] = dp[2] * dp[4] --> (8, 4, 2), (8, 2, 4)
		 *                  ^           ^^^^^^^^^  ^^^^^^^^^
		 *                  +---------------+----------+
		 *    => because left/right child tree can be switched
		 */
		unordered_map<int, long> dp;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			// each number is a tree with its value only
			dp[arr[i]] = 1;
			for (int j = 0; j < i; j++)
				// here A = arr[i], B = arr[j], C = arr[i] / arr[j]
				if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j]))
					dp[arr[i]] += (dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
		}
		// sum up the answer
		long ans = 0;
		for (auto& t : dp)
			ans += t.second % mod;
		return ans % mod;
	}
};
// @lc code=end

