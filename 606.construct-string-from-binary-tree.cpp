/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
	string tree2str(TreeNode* root) {
		if (!root) return "";

		string left = tree2str(root->left);
		string right = tree2str(root->right);

		if (left == "" && right == "") return to_string(root->val);
		if (left != "" && right == "") return to_string(root->val) + "(" + left + ")";
		if (left == "" && right != "") return to_string(root->val) + "()" + "(" + right + ")";
		return to_string(root->val) + "(" + left + ")" + "(" + right + ")";
	}
};
// @lc code=end
