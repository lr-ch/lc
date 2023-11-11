/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
class Graph {
	typedef pair<int, int> target;		// (weight, node#)
	unordered_map<int, vector<target>> adjs;
	int N;
public:
	Graph(int n, vector<vector<int>>& edges) : N(n) {
		for (auto& edge : edges)
			adjs[edge[0]].push_back({edge[2], edge[1]});
	}

	void addEdge(vector<int> edge) {
		adjs[edge[0]].push_back({edge[2], edge[1]});
	}

	int shortestPath(int node1, int node2) {
		priority_queue<target, vector<target>, greater<target>> pq;
		vector<int> nodeCost(N, INT_MAX);
		nodeCost[node1] = 0;
		pq.push({ 0, node1 });

		while (!pq.empty()) {
			auto [weight, node] = pq.top(); pq.pop();

			// visited?
			if (weight > nodeCost[node]) continue;

			if (node == node2) return weight;

			for (auto& next : adjs[node]) {
				auto [nextWeight, nextNode] = next;
				int cost = weight + nextWeight;

				if (cost < nodeCost[nextNode]) {
					nodeCost[nextNode] = cost;
					pq.push({cost, nextNode});
				}
			}
		}

		return -1;
	}
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end
