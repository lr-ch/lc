/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
		if (source == target) return 0;

		unordered_map<int, vector<int>> circle;     // (stop, passing buses)
		for (int i = 0; i < routes.size(); i++)
			for (auto& stop : routes[i])
				circle[stop].push_back(i);

		vector<bool> visited(routes.size(), false);
		queue<int> q;
		q.push(source);
		int buses = 0;

		while (!q.empty()) {
			int qsize = q.size();
			buses++;
			while (qsize--) {
				int curr = q.front(); q.pop();
				for (auto& bus : circle[curr]) {
					if (visited[bus]) continue;

					visited[bus] = true;
					for (auto& stop : routes[bus]) {
						if (stop == target) return buses;
						q.push(stop);
					}
				}
			}
		}

		return -1;
	}
};
// @lc code=end
