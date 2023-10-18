/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
class Solution {
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		unordered_map<int, vector<int>> adjs;	// (from, [to...])
		vector<int> ind(n + 1, 0);				// indegree
		for (auto& r : relations) {
			adjs[r[0]].push_back(r[1]);
			ind[r[1]]++;
		}

		queue<int> q;
		vector<int> course_time(n + 1, 0);		// index starts from 1
		for (int i = 1; i <=n; i++)
			if (ind[i] == 0) {
				q.push(i);
				course_time[i] = time[i - 1];
			}

		while (!q.empty()) {
			auto curr = q.front(); q.pop();
			for (auto& next : adjs[curr]) {
				course_time[next] = max(course_time[next], course_time[curr] + time[next - 1]);
				ind[next]--;
				if (ind[next] == 0)
					q.push(next);
			}
		}

		return *max_element(course_time.begin(), course_time.end());
	}
};
// @lc code=end
