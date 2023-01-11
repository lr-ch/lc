/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& t, vector<bool>& a, vector<bool>& v, int node) {
		v[node] = true;

		int time = 0;
		for (const auto& child : t[node]) {
			if (v[child]) continue;

			int cost = dfs(t, a, v, child);
			if (cost > 0 || a[child])
				time += 2 + cost;
		}

		return time;
	}

public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		vector<vector<int>> tree(n);
		for (const auto& e : edges) {
			tree[e[0]].push_back(e[1]);
			tree[e[1]].push_back(e[0]);
		}

		vector<bool> visited(n, false);
		return dfs(tree, hasApple, visited, 0);
	}
};
// @lc code=end
