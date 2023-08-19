/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

// @lc code=start
class Solution {
	struct UnionFind {
		vector<int> boss;

		UnionFind(int k)
			: boss(k) { iota(boss.begin(), boss.end(), 0); }

		int find(int x) {
			while (boss[x] != x) {
				boss[x] = boss[boss[x]];
				x = boss[x];
			}
			return boss[x];
		}

		bool unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				bossX > bossY ? boss[bossY] = bossX : boss[bossX] = bossY;
				return true;
			}
			return false;
		}
	};

	// Kruskal algorithm to calculate cost of MST
	int Kruskal(int n, vector<vector<int>>& edges, int exclude = -1, int include = -1) {
		int cost = 0;
		int count = 0;
		UnionFind uf(n);

		if (include >= 0) {
			cost += edges[include][2];
			uf.unite(edges[include][0], edges[include][1]);
			count++;
		}

		for (int i = 0; i < edges.size(); ++i) {
			if (i == exclude) continue;
			if (!uf.unite(edges[i][0], edges[i][1])) continue;

			cost += edges[i][2];
			++count;
		}

		return count == n - 1 ? cost : INT_MAX;
	};

public:
	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
		// add a new field for edge id
		for (int i = 0; i < edges.size(); ++i) edges[i].push_back(i);

		// sort edges by weight
		sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
			if (e1[2] == e2[2]) return e1 < e2;
			return e1[2] < e2[2];
		});

		int base = Kruskal(n, edges);
		vector<int> criticals;
		vector<int> pseudos;
		for (int i = 0; i < edges.size(); ++i) {
			if (Kruskal(n, edges, i) > base) {
				// if exclude this edge causes cost increase or not a tree anymore, it is critical
				criticals.push_back(edges[i][3]);
			} else if (Kruskal(n, edges, -1, i) == base) {
				pseudos.push_back(edges[i][3]);
			}
		}
		return {criticals, pseudos};
	}
};
// @lc code=end
