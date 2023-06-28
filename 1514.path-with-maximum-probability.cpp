/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<vector<pair<double, int>>> adjs(n);
		for (int i = 0; i < edges.size(); i++) {
			// e.g. log(0.1) = -1, log(0.01) = -2
			adjs[edges[i][0]].push_back({ -log(succProb[i]), edges[i][1] });
			adjs[edges[i][1]].push_back({ -log(succProb[i]), edges[i][0] });
		}

		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
		vector<bool> visited(n, false);

		pq.push({ 0.0, start });

		while (!pq.empty()) {
			auto [probc, curr] = pq.top(); pq.pop();
			visited[curr] = true;

			if (curr == end) return exp(-probc);

			for (const auto& [probn, next] : adjs[curr])
				if (!visited[next])
					pq.push({probc + probn, next});
		}
		return 0;
	}
};
// @lc code=end
