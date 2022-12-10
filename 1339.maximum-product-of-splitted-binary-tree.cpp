/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
	int accumulate(TreeNode* root) {
		if (!root) return 0;
		return root->val + accumulate(root->left) + accumulate(root->right);
	}

	long dfs(TreeNode* root, const int totalSum, long& ans) {
		if (!root) return 0;

		long subtreeSum = root->val + dfs(root->left, totalSum, ans) + dfs(root->right, totalSum, ans);
		ans = max(ans, subtreeSum * (totalSum - subtreeSum));
		return subtreeSum;
	}

	const int MOD = 1e9 + 7;
public:
	int maxProduct(TreeNode* root) {
		long ans = 0;

		long totalSum = accumulate(root);
		dfs(root, totalSum, ans);
		return (int)(ans % MOD);
	}
};
// @lc code=end
