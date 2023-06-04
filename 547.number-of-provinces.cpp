/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;
		int groups;

		UnionSet(int n) : groups(n) {
			boss.resize(n);
			iota(boss.begin(), boss.end(), 0);
		}

		int find(int n) {
			while (boss[n] != n) {
				boss[n] = boss[boss[n]];
				n = boss[n];
			}
			return boss[n];
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
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		UnionSet us(n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (isConnected[i][j])
					us.unite(i, j);

		return us.groups;
	}
};
// @lc code=end
