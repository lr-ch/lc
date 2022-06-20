/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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

		v.push_back(root->val);
		traverse(root->left, v);
		traverse(root->right, v);
	}
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int>	v;
		traverse(root, v);
		return v;
    }
};
// @lc code=end

