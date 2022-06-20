/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
	vector<vector<int>> ans;

	void bt(vector<int> path, vector<int> opts, vector<bool> consumed) {
		if (path.size() == opts.size()) {
			ans.push_back(path);
			return;
		}

		for (int i = 0; i < opts.size(); i++) {
			if (consumed[i] == false) {
				path.push_back(opts[i]);
				consumed[i] = true;
				bt(path, opts, consumed);
				path.pop_back();
				consumed[i] = false;
			}
		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> path;
		vector<bool> consumed(nums.size(), false);
		bt(path, nums, consumed);
		return ans;
	}
};
// @lc code=end

