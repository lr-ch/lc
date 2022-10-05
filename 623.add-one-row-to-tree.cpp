/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
	void traverse(TreeNode* root, int val, int depth, int currDepth) {
		if (!root) return;
		if (depth == 1) {
			TreeNode *left = new TreeNode(val, root, nullptr);
			newRoot = left;
			return;
		}
		if (currDepth == depth - 1) {
			TreeNode *left = new TreeNode(val, root->left, nullptr);
			root->left = left;
			TreeNode *right = new TreeNode(val, nullptr, root->right);
			root->right = right;
			return;
		}
		traverse(root->left, val, depth, currDepth + 1);
		traverse(root->right, val, depth, currDepth + 1);
	}

	TreeNode* newRoot;
public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		newRoot = root;
		traverse(root, val, depth, 1);
		return newRoot;
	}
};
// @lc code=end
