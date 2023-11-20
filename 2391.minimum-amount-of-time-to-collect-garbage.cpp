/*
 * @lc app=leetcode id=2391 lang=cpp
 *
 * [2391] Minimum Amount of Time to Collect Garbage
 */

// @lc code=start
class Solution {
public:
	int garbageCollection(vector<string>& garbage, vector<int>& travel) {
		int ans = 0, lastM = 0, lastP = 0, lastG = 0;

		for (int i = 0; i < garbage.size(); i++) {
			ans += garbage[i].length();		// collect time

			// record the farest distances for each truck to reach
			lastM = (garbage[i].find('M') == string::npos ? lastM : i);
			lastP = (garbage[i].find('P') == string::npos ? lastP : i);
			lastG = (garbage[i].find('G') == string::npos ? lastG : i);
		}

		if (lastM) ans += accumulate(travel.begin(), travel.begin() + lastM, 0);
		if (lastP) ans += accumulate(travel.begin(), travel.begin() + lastP, 0);
		if (lastG) ans += accumulate(travel.begin(), travel.begin() + lastG, 0);

		return ans;
	}
};
// @lc code=end
