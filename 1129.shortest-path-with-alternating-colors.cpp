/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
	typedef array<bool, 2> 	vState;		// visited state at [0] - red, [1] - blue edges

	vector<int> ans;
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		ans.resize(n, -1);
		ans[0] = 0;

		vector<vector<int>> red(n), blue(n);	// adj matrix
		for (const auto& r : redEdges) red[r[0]].push_back(r[1]);
		for (const auto& b : blueEdges) blue[b[0]].push_back(b[1]);

		vector<vState> nodeState(n, { false, false });

		queue<pair<int, int>> q;	// <node index, color>
		q.push({ 0, 0 });			// node#0, red edge
		q.push({ 0, 1 });			// node#0, blue edge
		int steps = 0;

		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [curr, color] = q.front(); q.pop();

				if (ans[curr] == -1) ans[curr] = steps;
				nodeState[curr][color] = true;

				vector<int> nextList = (color == 0 ? red[curr] : blue[curr]);
				int nextColor = color ? 0 : 1;
				for (int next : nextList)
					if (nodeState[next][nextColor] == false)
						q.push({ next, nextColor });
			}
			steps++;
		}
		return ans;
	}
};
// @lc code=end
