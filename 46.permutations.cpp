/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class SolutionBt1 {
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

class Solution {
	void bt(vector<int>& n, int i) {
		if (n.size() == i) {
			ans.push_back(n);
			return;
		}

		for (int j = i; j < n.size(); j++) {
			swap(n[i], n[j]);
			bt(n, i + 1);
			swap(n[i], n[j]);
		}
	}

	vector<vector<int>> ans;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		bt(nums, 0);
		return ans;
	}
};
// @lc code=end
