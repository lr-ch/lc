/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
	pair<int, int> traverse(TreeNode* root, int start) {
		if (!root) return {0, 0};

		auto [leftFound, depthLeft] = traverse(root->left, start);
		auto [rightFound, depthRight] = traverse(root->right, start);

		if (root->val == start) {
			maxDepth = max(depthLeft, depthRight);
			return {1, 1};
		} else if (leftFound) {
			maxDepth = max(maxDepth, depthLeft + depthRight);
			return {1, depthLeft + 1};
		} else if (rightFound) {
			maxDepth = max(maxDepth, depthLeft + depthRight);
			return {1, depthRight + 1};
		} else
			return {0, max(depthLeft, depthRight) + 1};
	}

	int maxDepth = 0;
public:
	int amountOfTime(TreeNode* root, int start) {
		traverse(root, start);
		return maxDepth;
	}
};
// @lc code=end
