/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	vector<TreeNode*> dfs(int start, int end) {
		if (start > end) return { nullptr };

		vector<TreeNode*> ret;
		for (int i = start; i <= end; i++) {
			auto left = dfs(start, i - 1), right = dfs(i + 1, end);
			for (const auto& l : left)
				for (const auto& r : right)
					ret.push_back(new TreeNode(i, l, r));
		}
		return ret;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if (!n) return {};
		return dfs(1, n);
	}
};
// @lc code=end
