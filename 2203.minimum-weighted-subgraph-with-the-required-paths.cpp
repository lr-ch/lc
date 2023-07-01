/*
 * @lc app=leetcode id=2203 lang=cpp
 *
 * [2203] Minimum Weighted Subgraph With the Required Paths
 */

// @lc code=start
class Solution {
	void dijkstra(vector<vector<pair<int, int>>>& v, vector<long long>& target, int s) {
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
		target[s] = 0;
		pq.push({0, s});
		while (!pq.empty()) {
			auto [weight, curr] = pq.top(); pq.pop();

			if (weight > target[curr]) continue;

			for (const auto& [n, w] : v[curr]) {
				if (target[n] > target[curr] + w) {
					target[n] = target[curr] + w;
					pq.push({target[n], n});
				}
			}
		}
	}

public:
	long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
		vector<vector<pair<int, int>>> adjs(n), reverse(n);
		for (const auto& e : edges) {
			adjs[e[0]].push_back({e[1], e[2]});
			reverse[e[1]].push_back({e[0], e[2]});
		}

		vector<long long> dist1(n, LONG_MAX), dist2(n, LONG_MAX), revDest(n, LONG_MAX);
		dijkstra(adjs, dist1, src1);
		dijkstra(adjs, dist2, src2);
		dijkstra(reverse, revDest, dest);

		if (revDest[src1] == LONG_MAX || revDest[src2] == LONG_MAX)
			return -1;

		long long ret = 9999900000LL + 1;
		for (int i = 0; i < n; i++) {
			if (dist1[i] == LONG_MAX || dist2[i] == LONG_MAX || revDest[i] == LONG_MAX)
				continue;   // should not be the answer...
			ret = min(ret, dist1[i] + dist2[i] + revDest[i]);
		}
		return ret;
	}
};
// @lc code=end
