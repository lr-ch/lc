/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
	int traverse(TreeNode* root) {
		if (!root) return 0;

		int left = max(0, traverse(root->left));
		int right = max(0, traverse(root->right));

		m = max(m, left + right + root->val);
		return max(left, right) + root->val;
	}

	int m = INT_MIN;
public:
	int maxPathSum(TreeNode* root) {
		traverse(root);
		return m;
	}
};
// @lc code=end

