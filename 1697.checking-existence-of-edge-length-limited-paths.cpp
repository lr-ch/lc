/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;

		UnionSet(int n)
			: boss(n)
		{ iota(boss.begin(), boss.end(), 0); }

		int find(int n) {
			while (n != boss[n]) {
				boss[n] = boss[boss[n]];
				n = boss[n];
			}
			return boss[n];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				if (bossX < bossY)
					boss[bossY] = bossX;
				else
					boss[bossX] = bossY;
			}
		}

		bool isConnected(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			return bossX == bossY;
		}
	};

public:
	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		UnionSet us(n);

		sort(edgeList.begin(), edgeList.end(), [](const auto& a, const auto& b) {
			return a[2] < b[2];		// ascending order by distance
		});

		vector<array<int, 4>> indexedQueries(queries.size());
		for (int i = 0; i < queries.size(); i++)
			indexedQueries[i] = {
				queries[i][0],
				queries[i][1],
				queries[i][2],
				i
			};
		sort(indexedQueries.begin(), indexedQueries.end(), [](const auto& a, const auto& b) {
			return a[2] < b[2];		// ascending order by distance
		});

		int edgeIndex = 0;
		vector<bool> ans(queries.size(), false);
		// iterate queries and generate union set
		for (const auto& q : indexedQueries) {
			int start = q[0], end = q[1], limit = q[2], index = q[3];

			while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit) {
				us.unite(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
				edgeIndex++;
			}

			ans[index] = us.isConnected(start, end);
		}
		return ans;
	}
};
// @lc code=end

