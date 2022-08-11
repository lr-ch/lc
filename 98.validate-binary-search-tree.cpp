/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
	/*
	 * In a BST, all nodes at left child tree must be smaller than the root,
	 * as well as all nodes at right child tree must be larger than the root.
	 *
	 * Validation on subtree only is not correct
	 */
	bool dfs(TreeNode* root, TreeNode *min, TreeNode *max) {
		if (!root) return true;

		if (min && root->val <= min->val) return false;
		if (max && root->val >= max->val) return false;

		return dfs(root->left, min, root) && dfs(root->right, root, max);
	}

public:
	bool isValidBST(TreeNode* root) {
		return dfs(root, nullptr, nullptr);
	}
};
// @lc code=end

