/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
	/*
	 * Hint: inorder sequence of a BST is actually a sorted array
	 */
	void dfs(TreeNode* root) {
		if (!root) return;

		dfs(root->left);
		if (prev)
			ans = min(ans, root->val - prev->val);
		prev = root;
		dfs(root->right);
	}

	TreeNode* prev = nullptr;
	int ans = INT_MAX;
public:
	int minDiffInBST(TreeNode* root) {
		dfs(root);
		return ans;
	}
};
// @lc code=end
