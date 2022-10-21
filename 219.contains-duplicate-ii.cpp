/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> table;	// <number, indices of the number>
		for (int i = 0; i < nums.size(); i++)
			table[nums[i]].push_back(i);

		for (auto& [_, indices] : table)
			if (indices.size() >= 2)
				for (int j = 0; j < indices.size() - 1; j++)
					if (indices[j + 1] - indices[j] <= k)
						return true;
		return false;
	}
};
// @lc code=end
