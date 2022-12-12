/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class SolutionDFS {
	void graphGen(int n, vector<vector<int>>& p, unordered_map<int, vector<int>>& g) {
		for (auto& pre : p) {
			int from = pre[1], to = pre[0];
			g[from].push_back(to);
		}
	}

	void traverse(unordered_map<int, vector<int>>& graph, int node) {
		if (going[node]) circular = true;
		if (visited[node] || circular) return;

		visited[node] = true;
		going[node] = true;
		for (auto& n : graph[node])
			traverse(graph, n);
		going[node] = false;
	}

	vector<bool> visited, going;
	bool circular = false;
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> graph;
		graphGen(numCourses, prerequisites, graph);

		visited.resize(numCourses, false);
		going.resize(numCourses, false);
		for (auto& [node, adjs] : graph)
			traverse(graph, node);

		return !circular;
	}
};

class SolutionBFS {
	void graphGen(int n, vector<vector<int>>& p, unordered_map<int, vector<int>>& g, vector<int>& id) {
		id.resize(n, 0);
		for (auto& pre : p) {
			int from = pre[1], to = pre[0];
			g[from].push_back(to);
			id[to]++;
		}
	}

	int traverse(unordered_map<int, vector<int>>& graph, vector<int>& id) {
		queue<int> q;
		for (auto& [key, _] : graph)
            if (id[key] == 0)
                q.push(key);

		while(!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				int node = q.front();
				q.pop();

				for (auto& adj : graph[node]) {
					id[adj]--;

					if (id[adj] == 0)
						q.push(adj);
				}
			}
		}

		return accumulate(id.begin(), id.end(), 0);
	}

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> graph;
		vector<int> indegree;
		graphGen(numCourses, prerequisites, graph, indegree);

		return 0 == traverse(graph, indegree);
	}
};

class Solution {
	/*
	 * Accepted
	 *  52/52 cases passed (57 ms)
	 *  Your runtime beats 26.38 % of cpp submissions
	 *  Your memory usage beats 41.41 % of cpp submissions (14.2 MB)
	 */
	SolutionDFS dfs;

	/*
	 * Accepted
	 *  52/52 cases passed (33 ms)
	 *  Your runtime beats 74.72 % of cpp submissions
	 *  Your memory usage beats 60.91 % of cpp submissions (13.8 MB)
	 */
	SolutionBFS bfs;

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	//	return dfs.canFinish(numCourses, prerequisites);
		return bfs.canFinish(numCourses, prerequisites);
	}
};
// @lc code=end
