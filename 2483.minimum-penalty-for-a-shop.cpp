/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 */

// @lc code=start
class Solution {
public:
	int bestClosingTime(const string& customers) {
		int currPenalty = accumulate(customers.begin(), customers.end(), 'Y');
		int minPenalty = currPenalty;
		int earliestHour = 0;
		int currHour = 0;

		for (int i = 0; i < customers.size(); i++) {
			// if customer comes in this hour, decrease the penalty by 1
			// otherwise increase penalty
			currPenalty += (customers[i] == 'Y' ? -1 : 1);

			if (currPenalty < minPenalty) {
				// update answer
				earliestHour = i + 1;	// this hour is opened, close shop next hour
				minPenalty = currPenalty;
			}
		}

		return earliestHour;
	}
};
// @lc code=end
