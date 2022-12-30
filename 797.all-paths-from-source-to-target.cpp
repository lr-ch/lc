/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
	void traverse(vector<vector<int>>& g, vector<int>& p, int node) {
		if (node == g.size() - 1) {
			paths.push_back(p);
			return;
		}

		for (auto& next : g[node]) {
			p.push_back(next);
			traverse(g, p, next);
			p.pop_back();
		}
	}

	vector<vector<int>> paths;
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> path;

		path.push_back(0);
		traverse(graph, path, 0);

		return paths;
	}
};
// @lc code=end
