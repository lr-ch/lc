/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class SolutionGen {
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

class SolutionDfs {
	bool paint(int node, int color, vector<vector<int>>& g) {
		if (colors[node]) return colors[node] == color;

		colors[node] = color;
		for (int adj : g[node])
			if (!paint(adj, -color, g))
				return false;
		return true;
	}

	vector<int> colors;
public:
	bool isBipartite(vector<vector<int>>& graph) {
		colors.resize(graph.size(), 0);

		for (int i = 0; i < graph.size(); i++)
			if (!colors[i] && !paint(i, 1, graph))
				return false;
		return true;
	}
};

class Solution {
	/*
	 * Accepted
	 *  81/81 cases passed (114 ms)
	 *  Your runtime beats 5.02 % of cpp submissions
	 *  Your memory usage beats 5.02 % of cpp submissions (19.4 MB)
	 */
	SolutionGen	gen;

	/*
	 * Accepted
	 *  81/81 cases passed (35 ms)
	 *  Your runtime beats 70.43 % of cpp submissions
	 *  Your memory usage beats 94.76 % of cpp submissions (13.4 MB)
	 */
	SolutionDfs dfs;

public:
	bool isBipartite(vector<vector<int>>& graph) {
	//	return gen.isBipartite(graph);
		return dfs.isBipartite(graph);
	}
};
// @lc code=end
