/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 */

// @lc code=start
class Solution {
public:
	int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		sort(arr2.begin(), arr2.end());		// sort for upper_bound()

		arr1.insert(arr1.begin(), -1);
		int N = arr1.size();
		/*
		 * dp[i][j] => with j swaps during arr1[0] ~ arr1[i], the minimun value at arr1[i],
		 *             so that arr1[i + 1] can concatenate to arr1[i] and keep strictly increasing
		 */
		vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
		dp[0][0] = -1;	// the minimun value of input arr1[0] is 0

		for (int i = 1; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				// if arr1[i] can concatenate to arr1[i - 1], update it to dp
				if (dp[i - 1][j] < arr1[i])
					dp[i][j] = min(dp[i][j], arr1[i]);

				// or we can swap arr1[i - 1] with a value in arr2 to make arr1[i] can concatenate to arr1[i - 1]
				if (j > 0) {
					// find the value just bit larger than dp[i][j - 1]
					auto iter = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
					if (iter != arr2.end())
						dp[i][j] = min(dp[i][j], *iter);
				}
			}
		}

		for (int k = 0; k < N; k++)
			if (dp[N - 1][k] != INT_MAX)
				return k;

		return -1;
	}
};
// @lc code=end
