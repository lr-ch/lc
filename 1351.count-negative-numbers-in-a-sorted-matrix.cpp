/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int ans = 0;
		for (const auto& v : grid)
			ans += count_if(v.begin(), v.end(), [](auto i){ return i < 0; });
		return ans;
	}
};
// @lc code=end
