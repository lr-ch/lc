/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
	array<char, 26> ord;
public:
	string customSortString(string order, string s) {
		iota(ord.begin(), ord.end(), 26);
		for (int i = 0; i < order.length(); i++)
			ord[order[i] - 'a'] = i;

		sort(s.begin(), s.end(), [this](const auto& a, const auto& b){
			return ord[a - 'a'] < ord[b - 'a'];
		});
		return s;
	}
};
// @lc code=end
