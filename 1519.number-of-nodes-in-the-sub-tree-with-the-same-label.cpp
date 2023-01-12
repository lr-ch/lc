/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
	array<int, 26> dfs(vector<vector<int>>& t, string& l, int node, vector<int>& r) {
		visited[node] = true;

		array<int, 26> count;
		fill(count.begin(), count.end(), 0);
		count[l[node] - 'a']++;

		for (const auto& child : t[node]) {
			if (visited[child]) continue;

			auto curr = dfs(t, l, child, r);
			for (int i = 0; i < 26; i++)
				count[i] += curr[i];
		}

		r[node] = count[l[node] - 'a'];
		return count;
	}

	vector<bool> visited;
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		vector<vector<int>> tree(n);
		for (const auto& e : edges) {
			tree[e[0]].push_back(e[1]);
			tree[e[1]].push_back(e[0]);
		}
		visited.resize(n, false);
		vector<int> ans(n);

		dfs(tree, labels, 0, ans);

		return ans;
	}
};
// @lc code=end
