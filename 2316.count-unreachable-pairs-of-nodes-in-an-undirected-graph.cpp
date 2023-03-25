/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;
		vector<int> group_size;

		UnionSet(int n) {
			boss.resize(n);
			for (int i = 0; i < n; i++) boss[i] = i;
			group_size.resize(n, 1);
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
				group_size[bossY] += group_size[bossX];
				// don't need to reset group_size[bossX], because we will get the
				// group_size of bossX by **group_size[find(bossX)]** instead of
				// **group_size[bossX]**
			//	group_size[bossX] = 0;
			}
		}
	};

public:
	long long countPairs(int n, vector<vector<int>>& edges) {
		long long ans = 0;
		UnionSet u(n);
		for (const auto& e : edges) u.unite(e[0], e[1]);

		for (int i = 0; i < u.group_size.size(); i++)
			ans += (n - u.group_size[u.find(i)]);

		return ans / 2;
	}
};
// @lc code=end
