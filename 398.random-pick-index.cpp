/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
	unordered_map<int, vector<int>> table;  // (number, array of number's indices)
public:
	Solution(vector<int>& nums) {
		// init random seed
		srand(time(nullptr));

		for (int i = 0; i < nums.size(); i++)
			table[nums[i]].push_back(i);
	}

	int pick(int target) {
		auto &indices = table[target];
		return indices[rand() % indices.size()];
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
