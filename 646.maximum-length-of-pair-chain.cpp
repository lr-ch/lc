/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		// asceding order
		sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
			return a[1] < b[1];
		});

		int cur = INT_MIN, ret = 0;
		for (const auto& p : pairs) {
			// second element alresdy sort by ascending order
			if (p[0] > cur) {
				ret++;
				cur = p[1];
			}
		}
		return ret;
	}
};
// @lc code=end
