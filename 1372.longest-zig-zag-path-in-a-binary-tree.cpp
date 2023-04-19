/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
	typedef enum dir {
		left,
		right
	};

	int dfs(TreeNode* root, dir go, int steps) {
		if (!root) return steps - 1;

		if (go == left)
			return max(dfs(root->right, right, steps + 1), dfs(root->left, left, 1));

		// go == right
		return max(dfs(root->left, left, steps + 1), dfs(root->right, right, 1));
	}

public:
	int longestZigZag(TreeNode* root) {
		return max(dfs(root, left, 0), dfs(root, right, 0));
	}
};
// @lc code=end
