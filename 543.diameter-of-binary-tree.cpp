/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
	int maxDepth(TreeNode* root, int& d) {
		if (!root) return 0;

		int left = maxDepth(root->left, d);
		int right = maxDepth(root->right, d);

		d = std::max(d, left + right);

		return 1 + std::max(left, right);
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = INT_MIN;
		maxDepth(root, diameter);
		return diameter;
	}
};
// @lc code=end

