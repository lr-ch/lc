/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */

// @lc code=start
class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		long long left = 1, right = (long long)*max_element(time.begin(), time.end()) * totalTrips;

		while (left < right) {
			long long mid = (left + right) / 2, trips = 0;
		//  cout << left << " : " << mid << " : " << right << "\n";
			for (const int& t : time) trips += (mid / t);

			if (trips < totalTrips)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
// @lc code=end

