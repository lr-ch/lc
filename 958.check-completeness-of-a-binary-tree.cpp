/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
	bool isCompleteTree(TreeNode* root) {
		if (!root) return true;

		bool nullAtSameLevel = false;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode *node = q.front(); q.pop();
			if (node == nullptr)
				nullAtSameLevel = true;

			if (node) {
				if (nullAtSameLevel) return false;
				q.push(node->left);
				q.push(node->right);
			} 
		}
		return true;
	}
};
// @lc code=end
