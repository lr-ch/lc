/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution {
	void count(vector<vector<int>>& b, int i) {
		for (int j = 0; j < N; j++) {
			if (j == i) continue;	// don't count self in

			int dx = b[i][0] - b[j][0],
				dy = b[i][1] - b[j][1],
				r = b[i][2];

			if (pow(dx, 2) + pow(dy, 2) <= pow(r, 2))
				chains[i].push_back(j);
		}
	}

	int N;
	vector<vector<int>> chains;		// chains[i] == list of bombs in radius of bomb[i]
public:
	int maximumDetonation(vector<vector<int>>& bombs) {
		N = bombs.size();
		chains.resize(N);

		for (int i = 0; i < N; i++) count(bombs, i);

		queue<int> q;
		int ret = 0;
		for (int i = 0; i < N; i++) {
			vector<bool> visited(N, false);		// in case of infinite loop
			int total = 1;						// total bombs detonated by bomb[i]
			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int bomb = q.front(); q.pop();
				for (const auto& b : chains[bomb]) {
					if (!visited[b]) {
						visited[b] = true;
						q.push(b);
						total++;
					}
				}
			}
			ret = max(ret, total);
		}

		return ret;
	}
};
// @lc code=end
