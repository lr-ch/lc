/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
class SolutionBFS {
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

class SolutionDFS {
	int dfs(int curr, vector<int>& t) {
		if (0 == adjs[curr].size()) return t[curr - 1];
		if (-1 != course_time[curr]) return course_time[curr];

		int res = 0;
		for (auto& next : adjs[curr])
			res = max(res, dfs(next, t));
		return course_time[curr] = res + t[curr - 1];
	}

	unordered_map<int, vector<int>> adjs;
	vector<int> course_time;
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		course_time.assign(n + 1, -1);
		for (auto& r : relations)
			adjs[r[0]].push_back(r[1]);

		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dfs(i, time));
		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 42/42 cases passed (331 ms)
	 *  - Your runtime beats 59.17 % of cpp submissions
	 *  - Your memory usage beats 42.62 % of cpp submissions (144.6 MB)
	 */
	SolutionBFS bfs;

	/*
	 * Accepted
	 *  - 42/42 cases passed (361 ms)
	 *  - Your runtime beats 41.37 % of cpp submissions
	 *  - Your memory usage beats 13.85 % of cpp submissions (157 MB)
	 */
	SolutionDFS dfs;
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
	//	return bfs.minimumTime(n, relations, time);
		return dfs.minimumTime(n, relations, time);
	}
};
// @lc code=end
