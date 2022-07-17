/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
class Solution {
	/*
	 * Assume a array of length (n - 1) which contains (p) pairs, adding the number (n) to
	 * the array will generate following results:
	 *
	 * +-+------+---+-+
	 * |0|......|n-1|n|  Put (n) at the last position, (n) is bigger than any other numbers
	 * +-+------+---+-+  p keeps the same, no change
	 *
	 * +-+------+-+---+
	 * |0|......|n|n-1|  Put (n) at second last position will generate new pair (n, n-1)
	 * +-+------+-+---+  p = (p) + 1
	 *
	 * +-+--+-+---+---+
	 * |0|..|n|n-2|n-1|  Put (n) at third last position will generate new pairs (n, n-2), (n, n-1)
	 * +-+--+-+---+---+  p = (p) + 2
	 *
	 * +-+--------+---+
	 * |n|........|n-1|  Put (n) at the first position will generate new pairs (n, 1), (n, 2)..., (n, n-1)
	 * +-+--------+---+  p = (p) + n - 1
	 *
	 * e.g. [1, 2, 3]       p = 0, Now add (4) to the array
	 *      [1, 2, 3, 4] -> p is still 0
	 *      [1, 2, 4, 3] -> p is 1, (4, 3)
	 *      [1, 4, 2, 3] -> p is 2, (4, 2), (4, 3)
	 *      [4, 1, 2, 3] -> p is 3, (4, 1), (4, 2), (4, 3)
	 *
	 * e.g.2 [2, 1, 3]       p = 1, (2, 1). Now add (4) to the array
	 *       [2, 1, 3, 4] -> p is still 1, (2, 1)
	 *       [2, 1, 4, 3] -> p is 2, (2, 1), (4, 3)
	 *       [2, 4, 1, 3] -> p is 3, (2, 1), (4, 1), (4, 3)
	 *       [4, 2, 1, 3] -> p is 4, (4, 2), (4, 1), (4, 3), (2, 1)
	 */
	/*
	 * Ref: https://leetcode.com/problems/k-inverse-pairs-array/discuss/2293256/
	 */
	int mod = 1000000007;

public:
	int kInversePairs(int n, int k) {
		// n numbers can generate at most n * (n - 1) / 2 inverse pairs
		if (k > n * (n - 1) / 2)
			return 0;

		if (k == n * (n - 1) / 2 || k == 0)
			return 1;

		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

		for (int i = 1; i < n + 1; i++) {
			dp[i][0] = 1;	// for j == 0
			for (int j = 1; j < min(k, i * (i - 1) / 2) + 1; j++) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - (j >= i ? dp[i - 1][j - i] : 0)) % mod;
				// all dp[i][j] modulo 10^9 + 7
				// so dp[i - 1][j - 1] might bigger than dp[i][j - 1] + dp[i - 1][j]
				if (dp[i][j] < 0)
					dp[i][j] += mod;
			}
		}

		return dp[n][k];
	}
};
// @lc code=end

