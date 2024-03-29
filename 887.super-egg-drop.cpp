/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution1 {
	/*
 	 * Time Limit Exceeded
 	 *  - 64/121 cases passed (N/A)
 	 *  - Testcase
 	 *     - 4
 	 *     - 10000
 	 */
	int dfs(vector<vector<int>>& m, int k, int n) {
		if (k == 0) return 0;	// no eggs left, search finished
		if (k == 1) return n;	// try from 1st -> n-th floor
		if (n <= 1) return n;	// one floor left, just try at that floor
		if (m[k][n] != INT_MAX) return m[k][n];
		for (int i = 1; i <= n; i++)
			m[k][n] = min(
						m[k][n],
						max(
							// if egg broke at floor#i, (i - 1) floors left to test
							dfs(m, k - 1, i - 1),
							// or egg did not break at floor#i, (n - i) floors left to test
							dfs(m, k, n - i)
							// plus this test
						) + 1
					);
		return m[k][n];
	}

	// optimize search of i with binary search
	int dfs2(vector<vector<int>>& m, int k, int n) {
		if (k == 0) return 0;	// no eggs left, search finished
		if (k == 1) return n;	// try from 1st -> n-th floor
		if (n <= 1) return n;	// one floor left, just try at that floor
		if (m[k][n] != INT_MAX) return m[k][n];

		int left = 1, right = n;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (dfs2(m, k - 1, mid - 1) >= dfs2(m, k, n - mid))
				right = mid;
			else
				left = mid + 1;
		}
		return m[k][n] = 1 + max(dfs2(m, k - 1, left - 1), dfs2(m, k, n - left));
	}

public:
	int superEggDrop(int k, int n) {
		// dp[k][n] = the minimun moves with k eggs and n floors
		vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));

	//	return dfs(dp, k, n);	// TLE
		return dfs2(dp, k, n);
	}
};

/*
 * ref. https://leetcode.com/problems/super-egg-drop/solutions/158974/c-java-python-2d-and-1d-dp-o-klogn/
 */
class Solution2 {
public:
	int superEggDrop(int k, int n) {
		// dp[m][k] the maximun floor can be certain with m moves and k eggs
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

		int m = 0;
		while (dp[m][k] < n) {
			m++;
			for (int eggs = 1; eggs <= k; eggs++)
				dp[m][eggs] = dp[m - 1][eggs - 1] + dp[m - 1][eggs] + 1;
		}
		return m;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 121/121 cases passed (76 ms)
	 *  - Your runtime beats 54.85 % of cpp submissions
	 *  - Your memory usage beats 20.64 % of cpp submissions (29.9 MB)
	 */
	Solution1 sol1;

	/*
	 * Accepted
	 *  - 121/121 cases passed (63 ms)
	 *  - Your runtime beats 70.21 % of cpp submissions
	 *  - Your memory usage beats 8.23 % of cpp submissions (47.8 MB)
	 */
	Solution2 sol2;
public:
	int superEggDrop(int k, int n) {
	//	return sol1.superEggDrop(k, n);
		return sol2.superEggDrop(k, n);
	}
};
// @lc code=end
