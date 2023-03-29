/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		sort(satisfaction.rbegin(), satisfaction.rend());

		int sum = 0, ans = 0;
		for (const auto& n : satisfaction) {
			sum += n;
			if (sum <= 0) break;
			ans += sum;
		}
		return ans;
	}
};
// @lc code=end
