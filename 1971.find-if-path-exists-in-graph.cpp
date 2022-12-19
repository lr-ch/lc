/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;

		UnionSet(int n) {
			boss.resize(n);
			for (int i = 0; i < n; i++) boss[i] = i;
		}

		int find(int x) {
			while (boss[x] != x) {
				boss[x] = boss[boss[x]];
				x = boss[x];
			}
			return boss[x];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);

			if (bossX == bossY) return;

			boss[bossX] = bossY;
		}
	};

public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		UnionSet us(n);

		for (int i = 0; i < edges.size(); i++) us.unite(edges[i][0], edges[i][1]);

		return us.find(source) == us.find(destination);
	}
};
// @lc code=end

