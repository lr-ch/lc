/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start

class SolutionSimple {
	void bt(vector<int>& n, vector<int>& p, int i) {
		if (i == n.size()) return;

		bool selected = false;
		if (p.empty() || n[i] >= p.back()) {
			selected = true;
			p.push_back(n[i]);
		}

		if (p.size() >= 2) ans.insert(p);

		for (int j = i + 1; j < n.size(); j++)
			bt(n, p, j);

		if (selected) p.pop_back();
	}

	set<vector<int>> ans;
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> path;

		for (int i = 0; i < nums.size(); i++)
			bt(nums, path, i);

		return vector<vector<int>>(ans.begin(), ans.end());
	}
};

class SolutionPreSelect {
	void bt(vector<int>& n, vector<int>& p, int i) {
		if (i == n.size()) return;
		if (p.size() > 1) ans.insert(p);

		for (int j = i + 1; j < n.size(); j++)
			if (n[j] >= p.back()) {
				p.push_back(n[j]);
				bt(n, p, j);
				p.pop_back();
			}
	}

	set<vector<int>> ans;
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> tmp;

		for (int i = 0; i < nums.size(); i++) {
			tmp.push_back(nums[i]);
			bt(nums, tmp, i);
			tmp.pop_back();
		}

		return vector<vector<int>>(ans.begin(), ans.end());
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 58/58 cases passed (114 ms)
	 *  - Your runtime beats 40.72 % of cpp submissions
	 *  - Your memory usage beats 68.8 % of cpp submissions (22.4 MB)
	 */
	SolutionSimple simple;

	/*
	 * Accepted
	 * 58/58 cases passed (76 ms)
	 * Your runtime beats 69.29 % of cpp submissions
	 * Your memory usage beats 73.89 % of cpp submissions (22.2 MB)
	 */
	SolutionPreSelect pre;
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
	//	return simple.findSubsequences(nums);
		return pre.findSubsequences(nums);
	}
};
// @lc code=end
