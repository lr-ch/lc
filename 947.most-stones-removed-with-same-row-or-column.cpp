/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
	struct UnionSet {
		map<int, int> boss;
		int count;

		UnionSet() { count = 0; }

		int find(int x) {
			if (boss.count(x) == 0) {
				boss[x] = x;
				count++;
			}

			if (boss[x] != x)
				boss[x] = find(boss[x]);

			return boss[x];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);

			if (bossX == bossY) return;

			boss[bossX] = bossY;
			count--;
		}
	};

public:
	int removeStones(vector<vector<int>>& stones) {
		UnionSet s;

		for (auto& stone : stones)
			s.unite(stone[0] + 1e4 + 1, stone[1]);

		return stones.size() - s.count;
	}
};
// @lc code=end
