/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
	set<vector<int>>	ans;

	void backtrack(vector<int> &path, vector<int> &track, vector<bool> &consumed) {
		if (path.size() == track.size()) {
			ans.insert(path);
			return;
		}

		for (int i = 0; i < track.size(); i++) {
			if (consumed[i] == false) {
				path.push_back(track[i]);
				consumed[i] = true;
				backtrack(path, track, consumed);
				consumed[i] = false;
				path.pop_back();
			}
		}
	}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int>	path;
		vector<bool> consumed(nums.size(), false);
		vector<vector<int>>	result;

		backtrack(path, nums, consumed);
		result.assign(ans.begin(), ans.end());
		return result;
    }
};
// @lc code=end
