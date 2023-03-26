/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

// @lc code=start
class Solution {
public:
	int longestCycle(vector<int>& edges) {
		vector<int> indegree(edges.size(), 0);
		vector<bool> visited(edges.size(), false);
		for (const auto& e : edges)
			if (e != -1) indegree[e]++;

		// trim off leaves (nodes with indegree == 0)
		queue<int> q;
		for (int i = 0; i < indegree.size(); i++)
			if (indegree[i] == 0) {
				visited[i] = true;
				q.push(i);
			}

		while (!q.empty()) {
			int node = q.front(); q.pop();
			// edges[node] --> the next node connected with node
			if (edges[node] != -1) {
				indegree[edges[node]]--;
				// push the next node to queue if it becomes leaf
				if (indegree[edges[node]] == 0) {
					visited[edges[node]] = true;
					q.push(edges[node]);
				}
			}
		}

		// now check cycle length
		int ans = -1;
		for (int i = 0; i < edges.size(); i++) {
			if (visited[i]) continue;

			int curr = i, cycle_length = 0;
			while (visited[curr] == false && curr != -1) {
				cycle_length++;
				visited[curr] = true;
				curr = edges[curr];
			}

			ans = max(ans, cycle_length);
		}
		return ans;
	}
};
// @lc code=end
