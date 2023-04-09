/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution {
public:
	int largestPathValue(string colors, vector<vector<int>>& edges) {
		int total = colors.length();	// number of nodes
		vector<vector<int>> adjs(total);
		vector<int> indegree(total, 0);
		for (const auto& e : edges) {
			adjs[e[0]].push_back(e[1]);
			indegree[e[1]]++;
		}

		// start from nodes with indegree == 0
		queue<int> q;
		for (int i = 0; i < total; i++)
			if (indegree[i] ==  0) q.push(i);

		vector<vector<int>> color_value(total, vector<int>(26, 0));
		int ans = 0, visited_node = 0;
		while (!q.empty()) {
			int node = q.front(); q.pop();

			ans = max(ans, ++color_value[node][colors[node] - 'a']);
			visited_node++;

			for (const auto& next : adjs[node]) {
				// update color value to next
				for (int c = 0; c < 26; c++)
					color_value[next][c] = max(color_value[next][c], color_value[node][c]);

				indegree[next]--;
				if (indegree[next] == 0)
					q.push(next);
			}
		}

		return visited_node == total ? ans : -1;
	}
};
// @lc code=end
