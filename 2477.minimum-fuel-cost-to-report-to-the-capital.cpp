/*
 * @lc app=leetcode id=2477 lang=cpp
 *
 * [2477] Minimum Fuel Cost to Report to the Capital
 */

// @lc code=start
class Solution {
	int dfs(unordered_map<int, vector<int>>& adjs, const int seats, int node, int parent) {
		int passengers = 0;

		for (int next : adjs[node])
			if (next != parent) {
				int tmp = dfs(adjs, seats, next, node);
				passengers += tmp;
				res += ceil(1.0 * tmp / seats);
			}

		return passengers + 1;
	}

	long long res = 0;
public:
	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		unordered_map<int, vector<int>> adjs;
		for (const auto& road : roads) {
			adjs[road[0]].push_back(road[1]);
			adjs[road[1]].push_back(road[0]);
		}

		dfs(adjs, seats, 0, -1);
		return res;
	}
};
// @lc code=end
