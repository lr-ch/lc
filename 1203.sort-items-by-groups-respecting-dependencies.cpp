/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 */

// @lc code=start
class Solution {
	vector<int> topologySort(vector<unordered_set<int>>& g, vector<int>& in) {
		vector<int> res;
		queue<int> q;
		for (int i = 0; i < in.size(); i++)
			if (in[i] == 0) q.push(i);  // start from leaf node

		while (!q.empty()) {
			int node = q.front(); q.pop();
			res.push_back(node);
			for (const auto& next : g[node])
				if (--in[next] == 0)
					q.push(next);
		}

		// if not all nodes are in res
		if (res.size() != in.size()) return {};
		return res;
	}

	void dump(vector<int>& v) {
		for (int i : v) cout << i << " ";
		cout << "\n";
	}

public:
	vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
		// for items belong no group, assign an exclusive vertual group
		for (auto &g : group) if (g == -1) g = m++;

		vector<unordered_set<int>> gGroup(m), gItems(n);    // graph
		vector<int> iGroup(m), iItems(n);                   // indegree
		// j -> i
		for (int i = 0; i < n; i++) {
			for (int j : beforeItems[i]) {
				// if not the same group and no duplicate edges
				if (group[i] != group[j] && !gGroup[group[j]].count(group[i])) {
					gGroup[group[j]].insert(group[i]);
					iGroup[group[i]]++;
				}

				if (!gItems[j].count(i)) {
					gItems[j].insert(i);
					iItems[i]++;
				}
			}
		}

		vector<int> orderedG = topologySort(gGroup, iGroup),
					orderedI = topologySort(gItems, iItems);
		if (orderedG.empty() || orderedI.empty()) return {};

	//	dump(orderedG);
	//	dump(orderedI);

		vector<int> res;
		vector<vector<int>> group2item(m);
		for (int item : orderedI) {
			group2item[group[item]].push_back(item);
		}
		for (int group_id : orderedG) {
			for (int item : group2item[group_id]) {
				res.push_back(item);
			}
		}
		return res;
	}
};
// @lc code=end
