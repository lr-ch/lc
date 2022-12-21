/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
	struct BiGraph {
		vector<vector<int>> graph;
		vector<bool> colors;
		vector<bool> visited;

		BiGraph(int n) {
			graph.resize(n);
			colors.resize(n, false);
			visited.resize(n, false);
		}

		void connect(int node, vector<int> adjs) {
			for (int adj : adjs) {
				graph[node].push_back(adj);
				graph[adj].push_back(node);
			}
		}

		void encolor(int node, bool color) {
			if (visited[node]) return;

			visited[node] = true;
			colors[node] = color;
			for (int adj : graph[node])
				encolor(adj, !color);	// paint adjancent nodes with contrary color
		}

		bool traverse(int node) {
			// check if two adjancent nodes has the same color
			for (int adj : graph[node])
				if (colors[node] == colors[adj])
					return false;
			return true;
		}
	};

public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();

		BiGraph bg(n);

		for (int i = 0; i < n; i++)
			bg.connect(i, graph[i]);

		for (int j = 0; j < n; j++)
			bg.encolor(j, true);

		for (int k = 0; k < n; k++)
			if (!bg.traverse(k))
				return false;

		return true;
	}
};
// @lc code=end

