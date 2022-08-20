/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
/*
 * Accepted
 *  * 198/198 cases passed (115 ms)
 *  * Your runtime beats 20.31 % of cpp submissions
 *  * Your memory usage beats 17.25 % of cpp submissions (16.7 MB)
 */
class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		vector<pair<int, int>> station_list;	// <miles, liters>
		for (auto& s : stations)
			station_list.push_back({s[0], s[1]});

		// dp[i] = the most distance can reach by stopping i stations
		vector<long> dp(stations.size() + 1, 0);

		// initial, the farest distance is startFuel miles
		dp[0] = startFuel;

		// for each stations, select the farest distance can reach
		for (int i = 0; i < stations.size(); i++)
			for (int j = i; j >= 0; j--)
				if (dp[j] >= station_list[i].first)
					dp[j + 1] = max(dp[j + 1], dp[j] + station_list[i].second);

		for (int k = 0; k < dp.size(); k++)
			if (dp[k] >= target)
				return k;

		return -1;
	}
};
// @lc code=end
