/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
	void split_group(int size, vector<int>& members) {
		vector<int> tmp;
		for (int i = 1; i <= members.size(); i++) {
			if (i % size == 0) {
				tmp.push_back(members[i - 1]);
				ret.push_back(tmp);
				tmp.clear();
			} else
				tmp.push_back(members[i - 1]);
		}
	}

	vector<vector<int>> ret;
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		unordered_map<int, vector<int>> groups;		// (group size, members)

		for (int i = 0; i < groupSizes.size(); i++)
			groups[groupSizes[i]].push_back(i);

		for (auto &[size, members] : groups) {
			if (members.size() > size)
				split_group(size, members);
			else
				ret.push_back(members);
		}

		return ret;
	}
};
// @lc code=end
