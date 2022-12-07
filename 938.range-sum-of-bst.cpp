/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
	int rangeSumBST(TreeNode* root, int low, int high) {
		if (!root) return 0;

		int nodeval = 0;
		if (root->val >= low && root->val <= high) nodeval = root->val;
		return nodeval + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
	}
};
// @lc code=end
