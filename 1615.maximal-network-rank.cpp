/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		if (!roads.size()) return 0;

		vector<int> degree(n + 1);
		vector<vector<bool>> adjs(n + 1, vector<bool>(n + 1, false));
		for (const auto& r : roads) {
			auto from = r[0], to = r[1];
			degree[from]++; degree[to]++;
			adjs[from][to] = true; adjs[to][from] = true;
		}

		int res = -1;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				int rank = degree[i] + degree[j] - (adjs[i][j] ? 1 : 0);
				res = max(res, rank);
			}

		return res;
	}
};
// @lc code=end
