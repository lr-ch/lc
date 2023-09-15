/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution {
	struct UnionFind {
		vector<int> boss;

		UnionFind(int n) : boss(n) {
			iota(boss.begin(), boss.end(), 0);
		}

		int find(int x) {
			while (boss[x] != x) {
				boss[x] = boss[boss[x]];
				x = boss[x];
			}
			return boss[x];
		}

		bool unite(int x, int y) {
			int bossX = find(x), bossY = find(y);
			if (bossX != bossY) {
				boss[bossX] = bossY;
				return true;
			}
			return false;
		}
	};

public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		vector<tuple<int, int, int>> edges;		// (distance(x->y), point x, point y)

		// enumerate all edges between points
		for (int i = 0; i < points.size() - 1; i++)
			for (int j = i + 1; j < points.size(); j++) {
				int dx = abs(points[i][0] - points[j][0]),
					dy = abs(points[i][1] - points[j][1]);
				edges.push_back({ dx + dy, i, j });
			}

		// sort edges by distance in ascending order
		sort(edges.begin(), edges.end());

		// construct tree
		int cost = 0;
		UnionFind uf(points.size());
		for (const auto& [c, x, y] : edges)
			// if point (x, y) is not united, add the edge into tree
			if (uf.unite(x, y))
				cost += c;

		return cost;
	}
};
// @lc code=end
