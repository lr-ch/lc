/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
public:
	void flatten(TreeNode* root) {
		if (!root) return;

		flatten(root->left);
		flatten(root->right);

		// switch left child to right
		TreeNode *right_tmp = root->right;
		root->right = root->left;
		root->left = nullptr;

		// find the leaf of right child
		TreeNode *p = root;
		while (p->right) p = p->right;

		// append original right child to the leaf
		p->right = right_tmp;
	}
};
// @lc code=end

