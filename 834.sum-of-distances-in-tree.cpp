/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution {
	int count_nodes_subtree(int node) {
		for (int adj : graph[node]) {
			if (visited[adj]) continue;

			visited[adj] = true;
			subtree_node_count[node] += count_nodes_subtree(adj);
		}
		return subtree_node_count[node];
	}

	int count_sum_distance(int node) {
		int sum = 0;
		for (int adj : graph[node]) {
			if (visited[adj]) continue;

			visited[adj] = true;
			sum += count_sum_distance(adj);
		}
		sum += subtree_node_count[node] - 1;
		return sum;
	}

	void traverse(int node, int n) {
		for (int adj : graph[node]) {
			if (visited[adj]) continue;

			visited[adj] = true;
			/*
			 * e.g.
			 *    0               2-5
			 *   / \             /|\
			 *  1   2     ->    0 3 4
			 *     /|\         /
			 *    3 4 5       1
			 *
			 *  Given total distance sum of node#0 is sum[0], what is sum[i]?
			 *  - Think about node#2,
			 *    - distance of nodes at left subtree of node#2 increase 1.
			 *    - distance of nodes at right subtree of node#2 decrease 1.
			 *  => sum[2] = sum[0] + node[2]'s left subtree size - node[2]'s right subtree size
			 *                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			 *                    total nodes (n) - sub_node_cnt[2]        sub_node_cnt[2]
			 *
			 *  => sum[child] = sum[parent] + n - 2 * subtree_node_count[child]
			 */
			answer[adj] = answer[node] + n - 2 * subtree_node_count[adj];
			traverse(adj, n);
		}
	}

	vector<vector<int>> graph;
	vector<int> subtree_node_count;
	vector<int> answer;
	vector<bool> visited;
public:
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		graph.resize(n);
		subtree_node_count.resize(n, 1);
		answer.resize(n, 0);
		visited.resize(n, false);

		// build graph
		for (auto& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		// count subtree nodes for each node
		visited[0] = true;
		count_nodes_subtree(0);					// count from node#0

		// count sum of distance from each node towards node#0
		fill(visited.begin(), visited.end(), false);
		visited[0] = true;
		answer[0] = count_sum_distance(0);		// take node#0 as root

		// reuse answer[0], calculate result for remain nodes
		fill(visited.begin(), visited.end(), false);
		visited[0] = true;
		traverse(0, n);

		return answer;
	}
};
// @lc code=end
