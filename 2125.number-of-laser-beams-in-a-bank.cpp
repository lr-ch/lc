/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		int ans = 0, prev = 0;
		for (auto& row : bank) {
			auto count_one = count(row.begin(), row.end(), '1');
			if (count_one) {
				ans += prev * count_one;
				prev = count_one;
			}
		}
		return ans;
	}
};
// @lc code=end
