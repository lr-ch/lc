/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
public:
	int minJumps(vector<int>& arr) {
		unordered_map<int, vector<int>> value_indices;
		vector<bool> visited(arr.size(), false);
		for (int i = arr.size() - 1; i >= 0; i--)
			value_indices[arr[i]].push_back(i);

		int steps = 0;
		queue<int> q;   // index
		q.push(0);		// start from arr[0]
		visited[0] == true;

		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				int index = q.front(); q.pop();
				if (index == arr.size() - 1) return steps;
				visited[index] = true;

				// jump to nodes having the same value
				for (auto& next : value_indices[arr[index]])
					if (!visited[next]) q.push(next);
				value_indices[arr[index]].clear();

				// or barckward/forward
				if (index + 1 < arr.size() && !visited[index + 1])
					q.push(index + 1);
				if (index - 1 >= 0 && !visited[index - 1])
					q.push(index - 1);
			}
			steps++;
		}
		return -1;
	}
};
// @lc code=end
