/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 *  76/94 cases passed (N/A)
	 */
/*
	int score(int m, int n, int remainMove, int currentRow, int currentCol) {
		if (currentRow < 0 || currentRow >= m || currentCol < 0 || currentCol >= n)
			return 1;
		if (remainMove == 0)
			return 0;

		return score(m , n, remainMove - 1, currentRow + 1, currentCol)
				 + score(m , n, remainMove - 1, currentRow - 1, currentCol)
				 + score(m , n, remainMove - 1, currentRow, currentCol + 1)
				 + score(m , n, remainMove - 1, currentRow, currentCol - 1);
	}

public:
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		return score(m, n, maxMove, startRow, startColumn) % 1000000007;
	}
*/
	long long mod = 1000000007;
	long long score(int m, int n, int remainMove, int currentRow, int currentCol,
				vector<vector<vector<long long>>>& dp)
	{
		if (currentRow < 0 || currentRow >= m || currentCol < 0 || currentCol >= n)
			return 1;
		if (remainMove == 0)
			return 0;

		if (dp[currentRow][currentCol][remainMove] != -1)
			return dp[currentRow][currentCol][remainMove];

		dp[currentRow][currentCol][remainMove] =
				score(m, n, remainMove - 1, currentRow + 1, currentCol, dp) % mod +
				score(m, n, remainMove - 1, currentRow - 1, currentCol, dp) % mod +
				score(m, n, remainMove - 1, currentRow, currentCol + 1, dp) % mod +
				score(m, n, remainMove - 1, currentRow, currentCol - 1, dp) % mod;

		return dp[currentRow][currentCol][remainMove];
	}

public:
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		vector<vector<vector<long long>>> memo(m,
											   vector<vector<long long>>(n,
											   vector<long long>(maxMove + 1, -1)));
		return score(m, n, maxMove, startRow, startColumn, memo) % mod;
	}
};
// @lc code=end

