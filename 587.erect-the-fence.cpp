/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution {
	int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
		return (q[1] - p[1]) * (r[0] - p[0]) - (q[0] - p[0]) * (r[1] - p[1]);
	}

public:
	vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
		vector<vector<int>> ans;
		sort(trees.begin(), trees.end(), [](const auto& a, const auto& b) {
			return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
		});

		// lower hull, left to right
		for (auto& tree : trees) {
			while (ans.size() > 1 && orientation(ans[ans.size() - 2], ans.back(), tree) > 0)
				ans.pop_back();
			ans.push_back(tree);
		}

		ans.pop_back();

		// upper hull, right to left
		reverse(trees.begin(), trees.end());
		for (auto& tree : trees) {
			while (ans.size() > 1 && orientation(ans[ans.size() - 2], ans.back(), tree) > 0)
				ans.pop_back();
			ans.push_back(tree);
		}

		// remove duplicated
		set<vector<int>> s(ans.begin(), ans.end());

		return vector<vector<int>>(s.begin(), s.end());
	}
};
// @lc code=end
