/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		unordered_set<string> outdegree;
		for (auto& cities : paths)
			outdegree.insert(cities[0]);

		for (auto& cities : paths)
			if (outdegree.find(cities[1]) == outdegree.end())
				return cities[1];

		return "";
	}
};
// @lc code=end
