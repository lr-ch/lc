/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
	int countNodes(TreeNode* root) {
		if (!root) return 0;

		queue<TreeNode *> q;
		q.push(root);

		int count = 0;
		while (!q.empty()) {
			int qsize = q.size();
			for (int i = 0; i < q.size(); i++) {
				TreeNode *node = q.front();
				q.pop();
				count++;

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return count;
	}
};
// @lc code=end
