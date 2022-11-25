/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
	const int MOD = 1000000007;
public:
	int sumSubarrayMins(vector<int>& arr) {
		stack<int> st;
		vector<int> dp(arr.size());

		for (int i = 0; i < arr.size(); i++) {
			while (!st.empty() && arr[st.top()] >= arr[i])
				st.pop();

			if (st.size() > 0) {
				int prevSmaller = st.top();
				dp[i] = dp[prevSmaller] + (i - prevSmaller) * arr[i];
			} else
				dp[i] = (i + 1) * arr[i];
			st.push(i);
		}

		long sum = 0;
		for (int count : dp) {
			sum += count;
			sum %= MOD;
		}

		return (int)sum;
	}
};
// @lc code=end

