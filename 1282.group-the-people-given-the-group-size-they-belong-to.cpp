/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		unordered_map<int, vector<int>> groups;		// (group size, members)
		vector<vector<int>> ret;

		for (int i = 0; i < groupSizes.size(); i++) {
			groups[groupSizes[i]].push_back(i);

			if (groups[groupSizes[i]].size() == groupSizes[i]) {
				ret.push_back(groups[groupSizes[i]]);
				groups[groupSizes[i]].clear();
			}
		}

		return ret;
	}
};
// @lc code=end
