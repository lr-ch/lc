/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		unordered_map<int, vector<int>> diag;
		for (int i = 0; i < nums.size(); i++)
			for (int j = 0; j < nums[i].size(); j++)
				diag[i + j].push_back(nums[i][j]);

		vector<int> ans;
		for (int i = 0; diag.find(i) != diag.end(); i++)
			ans.insert(ans.end(), diag[i].rbegin(), diag[i].rend());

		return ans;
	}
};
// @lc code=end
