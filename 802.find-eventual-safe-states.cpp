/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& g, int i) {
		if (state[i] != -1) return state[i];

		state[i] = 1;
		for (const int& next : g[i])
			if (dfs(g, next) == 1)
				return state[i] = 1;
		return state[i] = 0;
	}

	vector<int> state;	// -1 : unvisited, 1 : visiting, 0 : visited
	vector<int> ans;
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		state.resize(graph.size(), -1);

		for (int i = 0; i < graph.size(); i++)
			if (dfs(graph, i) == 0)
				ans.push_back(i);

		return ans;
	}
};
// @lc code=end
