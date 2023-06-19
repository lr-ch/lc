/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int ans = 0, alt = 0;
		for (int g : gain) ans = max(ans, alt += g);
		return ans;
	}
};
// @lc code=end
