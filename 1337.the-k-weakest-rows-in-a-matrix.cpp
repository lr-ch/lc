/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<pair<int, int>> order;			// (soldiers, row#)
		for (int i = 0; i < mat.size(); i++)
			order.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
		sort(order.begin(), order.end());

		vector<int> ans;
		for (int i = 0; i < k; i++)
			ans.push_back(order[i].second);
		return ans;
	}
};
// @lc code=end
