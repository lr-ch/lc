/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
	void traverse(TreeNode* root, vector<int>& v) {
		if (!root) return;

		traverse(root->left, v);
		traverse(root->right, v);
		v.push_back(root->val);
	}
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		traverse(root, v);
		return v;
	}
};
// @lc code=end

