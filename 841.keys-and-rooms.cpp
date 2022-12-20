/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int num_room = rooms.size();
		vector<int> visited(num_room, 0);
		queue<vector<int>> q;

		// first, visit room#0
		q.push(rooms[0]);
		visited[0] = 1;

		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				vector<int> keys = q.front();
				q.pop();

				for (int key : keys) {
					if (visited[key] == 1) continue;

					visited[key] = 1;		// mark visited on room# with key#
					q.push(rooms[key]);		// take keys from that room#
				}
			}
		}

		return accumulate(visited.begin(), visited.end(), 0) == num_room;
	}
};
// @lc code=end
