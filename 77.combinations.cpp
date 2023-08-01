/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
	void bt(int n, int k, int i, vector<int>& path) {
		if (path.size() == k) {
			ans.push_back(path);
			return;
		}

		for (int j = i; j <= n; j++) {
			path.push_back(j);
			bt(n, k, j + 1, path);
			path.pop_back();
		}
	}

	vector<vector<int>> ans;
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> tmp;
		bt(n, k, 1, tmp);
		return ans;
	}
};
// @lc code=end
