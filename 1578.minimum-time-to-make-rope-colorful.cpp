/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
public:
	int minCost(string colors, vector<int>& neededTime) {
		int slow = 0, fast = 0, timeTotal = 0;

		while (fast < colors.length()) {
			int timeMax = 0;
			while (fast < colors.length() && colors[fast] == colors[slow]) {
				timeMax = max(timeMax, neededTime[fast]);
				timeTotal += neededTime[fast];
				fast++;
			}
			timeTotal -= timeMax;
			slow = fast;
		}

		return timeTotal;
	}
};
// @lc code=end

