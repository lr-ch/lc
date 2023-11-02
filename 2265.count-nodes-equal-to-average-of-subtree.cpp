/*
 * @lc app=leetcode id=2265 lang=cpp
 *
 * [2265] Count Nodes Equal to Average of Subtree
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
	pair<int, int> dfs(TreeNode* root, int& count) {
		if (!root) return {0, 0};

		auto [leftN, leftSum] = dfs(root->left, count);
		auto [rightN, rightSum] = dfs(root->right, count);
		int sum = leftSum + rightSum + root->val;
		int n = leftN + rightN + 1;

		if (sum / n == root->val) count++;
		return {n, sum};
	}

public:
	int averageOfSubtree(TreeNode* root) {
		int count = 0;
		dfs(root, count);

		return count;
	}
};
// @lc code=end
