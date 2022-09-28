/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
	void bt(vector<int>& cand, vector<int>& opts, int target, int index) {
		if (target < 0) return;
		if (target == 0) {
			ans.push_back(opts);
			return;
		}

		for (int i = index; i < cand.size(); i++) {
			if (i > index && cand[i] == cand[i - 1])
				continue;
			opts.push_back(cand[i]);
			bt(cand, opts, target - cand[i], i + 1);
			opts.pop_back();
		}
	}

	vector<vector<int>> ans;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> options;
		sort(candidates.begin(), candidates.end());
		bt(candidates, options, target, 0);

		return ans;
	}
};
// @lc code=end
