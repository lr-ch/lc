/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
class SolutionSimpleDfs {
	bool dfs(TreeNode* root) {
		if (!root) return false;

		bool left = dfs(root->left);
		if (!left) root->left = nullptr;

		bool right = dfs(root->right);
		if (!right) root->right = nullptr;

		return left || right || root->val;
	}

public:
	TreeNode* pruneTree(TreeNode* root) {
		if (!dfs(root))
			return nullptr;
		return root;
	}
};

class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (!root) return nullptr;

		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (!root->left && !root->right && !root->val)
			return nullptr;
		return root;
	}
};
// @lc code=end
