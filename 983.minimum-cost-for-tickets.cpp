/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> dp(*days.rbegin() + 1, 0);	// assume days[days.size() - 1] is the last date

		// for each date, calculate the least cost
		for (int day = 1; day < dp.size(); day++) {
			if (find(days.begin(), days.end(), day) != days.end())
				dp[day] = min({
							dp[max(0, day -  1)] + costs[0],
							dp[max(0, day -  7)] + costs[1],
							dp[max(0, day - 30)] + costs[2] });
			else
				dp[day] = dp[day - 1];
		}
		return *dp.rbegin();
	}
};
// @lc code=end
