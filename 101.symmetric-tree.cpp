/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
	bool validate(TreeNode* left, TreeNode* right) {
		if (!left && !right) return true;		// both null
		if (!left || !right) return false;		// only one is null
		return left->val == right->val &&
				validate(left->left, right->right) &&
				validate(left->right, right->left);
	}

public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return validate(root->left, root->right);
	}
};
// @lc code=end
