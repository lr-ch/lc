/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		unordered_set<int> ing;

		for (int i = 0; i < n; i++) ing.insert(i);

		for (const auto& e : edges) ing.erase(e[1]);

		return vector<int>(ing.begin(), ing.end());
	}
};
// @lc code=end
