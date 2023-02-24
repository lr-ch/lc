/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		int mini = INT_MAX;
		priority_queue<int> q;
		for (int n : nums) {
			n = (n % 2 ? n * 2 : n);
			q.push(n);
			mini = min(mini, n);
		}

		int ans = q.top() - mini;
		while (q.top() % 2 == 0) {
			int maxi = q.top(); q.pop();
			q.push(maxi / 2);
			mini = min(mini, maxi / 2);
			ans = min(ans, q.top() - mini);
		}
		return ans;
	}
};
// @lc code=end
