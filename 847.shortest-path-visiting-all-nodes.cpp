/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int N = graph.size();
		vector<vector<int>> checked(N, vector<int>(1 << N));

		queue<pair<int, bitset<12>>> q;		// (curre node#, visited nodes)
		for (int i = 0; i < N; i++)
			q.push({i, 1 << i});			// all nodes can be start point
		int steps = 0;
		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [curr, visited] = q.front(); q.pop();
				if (visited.count() == N) return steps;

				// skip if this node was visited with the same visited state,
				// T.L.E without this two lines
				if (checked[curr][visited.to_ulong()]) continue;
				checked[curr][visited.to_ulong()] = 1;

				for (const auto& next : graph[curr]) {
					auto tmp = visited;
					q.push({next, tmp.set(next)});
				}
			}
			steps++;
		}
		return INT_MAX;
	}
};
// @lc code=end
