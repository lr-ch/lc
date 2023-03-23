/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;
		int groups;

		UnionSet(int n) {
			boss.resize(n);
			for (int i = 0; i < n; i++) boss[i] = i;
			groups = n;
		}

		int find(int i) {
			while (boss[i] != i) {
				boss[i] = boss[boss[i]];
				i = boss[i];
			}
			return boss[i];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				boss[bossX] = bossY;
				groups--;
			}
		}
	};

public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (connections.size() < n - 1) return -1;

		UnionSet u(n);
		for (const auto& edge : connections)
			u.unite(edge[0], edge[1]);

		return u.groups - 1;
	}
};
// @lc code=end
