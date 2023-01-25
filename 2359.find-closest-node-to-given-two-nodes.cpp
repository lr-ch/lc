/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
class Solution {
	void dump(vector<int>& v) {
		for (const auto i : v)
			cout << i << " ";
		cout << endl;
	}

	void bfs(vector<int>& edges, vector<int>& distance, int node) {
		int dis = 0;
		do {
			distance[node] = dis++;
			node = edges[node];
		} while (node != -1 && distance[node] == -1);
	}

public:
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		int n = edges.size();

		// get distance of every node toward node#1, #2
		vector<int> distance1(n, -1);
		bfs(edges, distance1, node1);
	//	dump(distance1);
		vector<int> distance2(n, -1);
		bfs(edges, distance2, node2);
	//	dump(distance2);

		// get the distance and the index on node#i
		int distance = INT_MAX, index = -1;
		for (int i = 0; i < n; i++) {
			if (distance1[i] == -1 || distance2[i] == -1) continue;

			int dis = max(distance1[i], distance2[i]);
			if (distance > dis) {
				distance = dis;
				index = i;
			}
		}

		return index;
	}
};
// @lc code=end
