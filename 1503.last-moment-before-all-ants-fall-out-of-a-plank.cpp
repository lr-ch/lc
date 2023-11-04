/*
 * @lc app=leetcode id=1503 lang=cpp
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
class Solution {
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		/*
		 * when two ants (toL->, <-toR) meet, they can be treated as swap their IDs
		 * e.g. (<-toL, toR->) is equivilant to (<-toR, toL->), they just pass through
		 * each other
		 *
		 * so the answer is only to find out the farest distance to right/left edges
		 */
		int toLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
		int toRight = right.empty() ? 0 : n - *min_element(right.begin(), right.end());
		return max(toLeft, toRight);
	}
};
// @lc code=end
