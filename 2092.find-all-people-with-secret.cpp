/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
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
			return x;
		}

		void unite(int x, int y) {
			int bossX = find(x), bossY = find(y);
			if (bossX != bossY)
				bossX < bossY ? boss[bossY] = bossX : boss[bossX] = bossY;
		}
	};

public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		UnionFind uf(n);
		uf.unite(0, firstPerson);

		sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
			return a[2] < b[2];
		});

		for (int i = 0; i < meetings.size(); i++) {
			unordered_set<int> associated;
			int j = i;

			do {
				uf.unite(meetings[j][0], meetings[j][1]);
				associated.insert(meetings[j][0]);
				associated.insert(meetings[j][1]);
				j++;
			} while (j < meetings.size() && meetings[j - 1][2] == meetings[j][2]);

			// de-unite n if its boss is not 0
			// in case of
			//    [0, a, 0]
			//    [a, b, 1]
			//    [c, d, 1]
			//    [a, d, 2] -> c should not have secret here
			for (const auto& n : associated)
				if (uf.find(n) != 0) uf.boss[n] = n;

			i = j - 1;	// fast-forward to next different meeting time
		}

		vector<int> ans;
		for (int i = 0; i < uf.boss.size(); i++)
			if (uf.find(i) == 0) ans.push_back(i);
		return ans;
	}
};
// @lc code=end
