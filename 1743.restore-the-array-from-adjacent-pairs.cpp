/*
 * @lc app=leetcode id=1743 lang=cpp
 *
 * [1743] Restore the Array From Adjacent Pairs
 */

// @lc code=start
class Solution {
	void dfs(int curr, int prev, unordered_map<int, vector<int>>& adjs, vector<int>& ans) {
		ans.push_back(curr);
		for (auto& next : adjs[curr])
			if (next != prev)
				dfs(next, curr, adjs, ans);
	}

public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, vector<int>> adjs;
		for (auto& p : adjacentPairs) {
			adjs[p[0]].push_back(p[1]);
			adjs[p[1]].push_back(p[0]);
		}

		int head;
		for (auto& [n, nv] : adjs)
			if (nv.size() == 1) {
				head = n;
				break;
			}

		vector<int> ans;
		dfs(head, INT_MIN, adjs, ans);
		return ans;
	}
};
// @lc code=end
