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
class DP {
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
				// if current distance can reach this station
				if (dp[j] >= station_list[i].first)
					// then the farest distance to next station (dp[j + 1]) is :
					// current distance (dp[j]) + station's fuel (station_list[i].second)
					// or it is already the farest distance
					dp[j + 1] = max(dp[j] + station_list[i].second, dp[j + 1]);

		for (int k = 0; k < dp.size(); k++)
			if (dp[k] >= target)
				return k;

		return -1;
	}
};

/*
 * Accepted
 *  * 198/198 cases passed (24 ms)
 *  * Your runtime beats 97.25 % of cpp submissions
 *  * Your memory usage beats 17 % of cpp submissions (16.9 MB)
 */
class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		vector<pair<int, int>> station_list;	// <miles, liters>
		for (auto& s : stations)
			station_list.push_back({s[0], s[1]});

		priority_queue<int> fuel;

		long currentDistance = startFuel;		// integer overflow?
		int count = 0, station = 0;				// NOTE: Do NOT reset station in loop process

		while (currentDistance < target) {
			// store the fuel to priority_queue for every valid station
			while (station < stations.size() &&
					currentDistance >= station_list[station].first) {
				fuel.push(station_list[station].second);
				station++;
			}

			// if there is no valid station
			if (fuel.empty())
				return -1;

			// select the station has most fuel so we can reach the farest distance
			currentDistance += fuel.top();
			fuel.pop();
			count++;
		}
		return count;
	}
};
// @lc code=end
