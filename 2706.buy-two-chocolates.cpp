/*
 * @lc app=leetcode id=2706 lang=cpp
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution {
public:
	int buyChoco(vector<int>& prices, int money) {
		sort(prices.begin(), prices.end());
		int left = money - prices[0] - prices[1];
		return left >= 0 ? left : money;
	}
};
// @lc code=end
