/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int m = strs.size(), n = strs[0].length(), ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (strs[j][i] < strs[j - 1][i]) {
					ans++;
					break;
				}
			}
		}

		return ans;
	}
};
// @lc code=end
