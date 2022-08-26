/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
	vector<vector<int>> res;
	void bt(vector<int>& c, int target, vector<int>& opts, int ci) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(opts);
			return;
		}

		for (int i = ci; i < c.size(); i++) {
			opts.push_back(c[i]);
			bt(c, target - c[i], opts, i);
			opts.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> tmp;
		bt(candidates, target, tmp, 0);
		return res;
	}
};
// @lc code=end

