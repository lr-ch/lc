/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
	struct BiGraph {
		vector<vector<int>> nodes;
		vector<bool> colors;
		vector<bool> visited;

		BiGraph(int n) {
			nodes.resize(n);
			colors.resize(n);
			visited.resize(n, false);
		}

		void connect(int node1, int node2) {
			nodes[node1].push_back(node2);
			nodes[node2].push_back(node1);
		}

		void encolor(int node, bool color) {
			if (visited[node]) return;

			visited[node] = true;
			colors[node] = color;

			// now paint adjacent nodes with contrary color
			for (int adj : nodes[node]) encolor(adj, !color);
		}

		bool traverse(int node) {
			for (int adj : nodes[node])
				if (colors[node] == colors[adj])
					return false;
			return true;
		}
	};

public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		BiGraph bg(n);
		for (auto& dislike : dislikes)
			bg.connect(dislike[0] - 1, dislike[1] - 1);		// node[1..n] => node[0..n-1]

		for (int i = 0; i < n; i++)
			bg.encolor(i, true);

		for (int i = 0; i < n; i++)
			if (!bg.traverse(i))
				return false;

		return true;
	}
};
// @lc code=end

