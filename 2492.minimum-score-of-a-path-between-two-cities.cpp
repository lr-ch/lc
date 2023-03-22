/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution {
public:
	int minScore(int n, vector<vector<int>>& roads) {
		vector<vector<pair<int, int>>> adjs_score(n + 1);
		vector<bool> visited(n + 1, false);

		for (const auto& road : roads) {
			adjs_score[road[0]].push_back({ road[1], road[2] });
			adjs_score[road[1]].push_back({ road[0], road[2] });
		}

		int ans = INT_MAX;
		queue<int> q;
		q.push(1);
		visited[1] = true;

		while (!q.empty()) {
			const auto node = q.front(); q.pop();

			for (const auto& [next, score] : adjs_score[node]) {
				ans = min(ans, score);
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
				}
			}
		}
		return ans;
	}
};
// @lc code=end
