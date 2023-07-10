/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
	int minDepth(TreeNode* root) {
		queue<TreeNode *> q;
		if (root) q.push(root);

		int steps = 1;
		while (!q.empty()) {
			int qsize = q.size();

			while (qsize--) {
				TreeNode *node = q.front(); q.pop();
				if (!node->left && !node->right) return steps;
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			steps++;
		}
		return 0;
	}
};
// @lc code=end
