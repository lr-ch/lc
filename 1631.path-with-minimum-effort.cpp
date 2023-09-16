/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class SolutionBFS {
	const vector<pair<int, int>> dirs= {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int R = heights.size(), C = heights[0].size();
		array<array<int, 100>, 100> dp;
		for (auto& arr : dp) arr.fill(INT_MAX);
		dp[0][0] = 0;
		for (int i = 0; i < max(R, C); i++)
			for (int m = 0; m < R; m++)
				for (int n = 0; n < C; n++)
					for (const auto& [dr, dc] : dirs) {
						int nr = m + dr, nc = n + dc;
						if (nr < 0 || nr >= R || nc < 0 || nc >= C)
							continue;
						dp[m][n] = min(
									dp[m][n],
									max(
										dp[nr][nc],
										abs(heights[nr][nc] - heights[m][n])
									));
					}
		return dp[R - 1][C - 1];
	}
};

class SolutionBinS {
	bool bfs(vector<vector<int>>& h, int cost) {
		vector<vector<bool>> visited(R, vector<bool>(C, false));
		queue<pair<int, int>> q;
		q.push({0, 0});
		visited[0][0] = true;
		while (!q.empty()) {
			auto [r, c] = q.front(); q.pop();
			if (r == R - 1 && c == C - 1) return true;

			for (const auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc;

				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (visited[nr][nc]) continue;
				if (abs(h[nr][nc] - h[r][c]) > cost) continue;

				q.push({nr, nc});
				visited[nr][nc] = true;
			}
		}
		return false;
	}

	const vector<pair<int, int>> dirs= {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int R, C;
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		R = heights.size();
		C = heights[0].size();
		int left = 0, right = 1e6;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (bfs(heights, mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};

class SolutionDijkstra {
	const vector<pair<int, int>> dirs= {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int R = heights.size(), C = heights[0].size();
		vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
		priority_queue<
			tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<>
		> pq;
		pq.push({0, 0, 0});
		dist[0][0] = 0;

		while (!pq.empty()) {
			auto [effort, r, c] = pq.top(); pq.pop();

			if (effort > dist[r][c]) continue;
			if (r == R - 1 && c == C - 1) return effort;

			for (const auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc;

				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

				int next_effort = max(effort, abs(heights[nr][nc] - heights[r][c]));
				if (next_effort < dist[nr][nc]) {
					dist[nr][nc] = next_effort;
					pq.push({next_effort, nr, nc});
				}
			}
		}
		return INT_MAX;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 75/75 cases passed (1170 ms)
	 *  - Your runtime beats 5.01 % of cpp submissions
	 *  - Your memory usage beats 99.9 % of cpp submissions (15.6 MB)
	 */
	SolutionBFS bfs;

	/*
	 * Accepted
	 *  - 75/75 cases passed (346 ms)
	 *  - Your runtime beats 14.33 % of cpp submissions
	 *  - Your memory usage beats 11.66 % of cpp submissions (50.9 MB)
	 */
	SolutionBinS bs;

	/*
	 * Accepted
	 *  - 75/75 cases passed (108 ms)
	 *  - Your runtime beats 73.36 % of cpp submissions
	 *  - Your memory usage beats 37.48 % of cpp submissions (20.3 MB)
	 */
	SolutionDijkstra dijk;
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
	//	return bfs.minimumEffortPath(heights);
	//	return bs.minimumEffortPath(heights);
		return dijk.minimumEffortPath(heights);
	}
};
// @lc code=end
