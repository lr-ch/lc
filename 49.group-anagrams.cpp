/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<int>> table;

		for (int i = 0; i < strs.size(); i++) {
			string sorted = strs[i];
			sort(sorted.begin(), sorted.end());
			table[sorted].push_back(i);
		}

		vector<vector<string>> ans;
		for (auto& [_, indices] : table) {
			vector<string> tmp;
			for (auto& index : indices)
				tmp.push_back(strs[index]);
			ans.push_back(tmp);
		}

		return ans;
	}
};
// @lc code=end
