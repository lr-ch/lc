/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		vector<vector<int>> members(n);		// members[i] == id list of manager#i
		for (int i = 0; i < n; i++)
			if (manager[i] != -1)
				members[manager[i]].push_back(i);

		int curr_time = 0;
		queue<pair<int, int>> q;
		q.push( { headID, curr_time });

		while (!q.empty()) {
			auto [mgr, time] = q.front(); q.pop();

			for (const auto& id : members[mgr])
				q.push({ id, time + informTime[mgr] });

			curr_time = max(curr_time, time);
		}

		return curr_time;
	}
};
// @lc code=end
