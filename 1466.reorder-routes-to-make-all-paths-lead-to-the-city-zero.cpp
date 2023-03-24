/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& adjs, int prev, int curr) {
		int reversed = 0;
		for (const auto& next : adjs[curr]) {
			if (abs(next) != prev) {	// don't go backward!
				if (next < 0) reversed++;
				reversed += dfs(adjs, curr, abs(next));
			}
		}
		return reversed;
	}

public:
	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<int>> adjs(n);
		for (const auto& edge : connections) {
			adjs[edge[0]].push_back(-edge[1]);
			adjs[edge[1]].push_back(edge[0]);
		}
		return dfs(adjs, -1, 0);
	}
};
// @lc code=end
