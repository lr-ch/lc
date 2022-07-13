/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
	vector<vector<int>> ans;

	void traverse(TreeNode* root, int level) {
		if (root == nullptr) return;

		// we go pre-order traversal,
		// so ans[level] must have been initialized before going deeper
		if (ans.size() == level)
			// ans[level] is not exsited (first time come to this level)
			ans.push_back(vector<int>{root->val});
		else
			ans[level].push_back(root->val);

		traverse(root->left, level + 1);
		traverse(root->right, level + 1);
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		traverse(root, 0);
		return ans;
	}
};
// @lc code=end

