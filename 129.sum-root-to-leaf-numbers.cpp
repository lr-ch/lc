/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
	int traverse(TreeNode* root, int val) {
		if (!root) return 0;
		if (!root->left && !root->right) return val * 10 + root->val;

		int left = traverse(root->left, val * 10 + root->val);
		int right = traverse(root->right, val * 10 + root->val);

		return left + right;
	}
public:
	int sumNumbers(TreeNode* root) {
		return traverse(root, 0);
	}
};
// @lc code=end
