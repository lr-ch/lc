/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;
		int groups;

		UnionSet(int n)
			: boss(n), groups(n)
		{ iota(boss.begin(), boss.end(), 0); }

		int find(int n) {
			while (n != boss[n]) {
				boss[n] = boss[boss[n]];
				n = boss[n];
			}
			return boss[n];
		}

		int unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				if (bossX <bossY)
					boss[bossY] = bossX;
				else
					boss[bossX] = bossY;
				groups--;
				return 0;
			}
			return 1;
		}
	};

public:
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		int ans = 0;
		// NOTE. the node# starts from 1
		UnionSet alice(n), bob(n);

		for (const auto& e : edges) {
			if (e[0] != 3) continue;
			ans += alice.unite(e[1] - 1, e[2] - 1);		// the node# starts from 1
		}
		bob = alice;

		for (const auto& e : edges) {
			if (e[0] == 3) continue;
			if (e[0] == 1)
				ans += alice.unite(e[1] - 1, e[2] - 1);
			else
				ans += bob.unite(e[1] - 1, e[2] - 1);
		}

		return (alice.groups == 1 && bob.groups == 1) ? ans : -1;
	}
};
// @lc code=end
