/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start

/*
 * ref. [887] Super Egg Drop
 */
class Solution2D {
public:
	int twoEggDrop(int n) {
		// dp[m][k] := make certainty of highest floor with m moves and k eggs, (0 <= k <= 2)
		vector<vector<int>> dp(n + 1, vector<int>(3, 0));
		int m = 0;
		while (dp[m][2] < n) {
			m++;
			for (int i = 1; i <= 2; i++)
				dp[m][i] = dp[m - 1][i - 1] + dp[m - 1][i] + 1;
		}
		return m;
	}
};

class SolutionOpt {
public:
	int twoEggDrop(int n) {
		vector<int> dp(3, 0);
		int m;
		for (m = 0; dp[2] < n; m++)
			for (int eggs = 2; eggs > 0; eggs--)
				dp[eggs] += dp[eggs - 1] + 1;
		return m;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 139/139 cases passed (7 ms)
	 *  - Your runtime beats 53.38 % of cpp submissions
	 *  - Your memory usage beats 7.52 % of cpp submissions (9.2 MB)
	 */
	Solution2D sol2d;

	/*
	 * Accepted
	 *  - 139/139 cases passed (0 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 43.77 % of cpp submissions (6.3 MB)
	 */
	SolutionOpt solOpt;
public:
	int twoEggDrop(int n) {
	//	return sol2d.twoEggDrop(n);
		return solOpt.twoEggDrop(n);
	}
};
// @lc code=end
