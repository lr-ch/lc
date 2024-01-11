/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
	pair<int, int> dfs(TreeNode* root) {
		pair<int, int> minmaxLeft = {root->val, root->val};
		pair<int, int> minmaxRight = {root->val, root->val};

		if (root->left) minmaxLeft = dfs(root->left);
		if (root->right) minmaxRight = dfs(root->right);

		ans = max({
					ans,
					max(abs(root->val - minmaxLeft.first), abs(root->val - minmaxRight.first)),
					max(abs(root->val - minmaxLeft.second), abs(root->val - minmaxRight.second))
				});

		return {
				min({minmaxLeft.first, minmaxRight.first, root->val}),
				max({minmaxLeft.second, minmaxRight.second, root->val})
			};
	}

	int ans = 0;
public:
	int maxAncestorDiff(TreeNode* root) {
		dfs(root);
		return ans;
	}
};
// @lc code=end
