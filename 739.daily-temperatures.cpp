/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();

		stack<pair<int, int>> s;	// <temperature, index>
		vector<int> ans(n);

		for (int j = n - 1; j >= 0; j --) {
			while (!s.empty() && s.top().first <= temperatures[j]) s.pop();
			ans[j] = s.empty() ? 0 : s.top().second - j;
			s.push({ temperatures[j], j });
		}
		return ans;
	}
};
// @lc code=end
