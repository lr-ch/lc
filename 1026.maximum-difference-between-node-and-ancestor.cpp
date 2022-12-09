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
	int tripleMax(int a, int b, int c) {
		return max(a, max(b, c));
	}

	int tripleMin(int a, int b, int c) {
		return min(a, min(b, c));
	}

	pair<int, int> dfs(TreeNode* root, int& ans) {
		pair<int, int> minmaxLeft = {root->val, root->val };
		pair<int, int> minmaxRight = {root->val, root->val };

		if (root->left) minmaxLeft = dfs(root->left, ans);
		if (root->right) minmaxRight = dfs(root->right, ans);

		ans = tripleMax(
				ans,
				max(abs(root->val - minmaxLeft.first), abs(root->val - minmaxRight.first)),
				max(abs(root->val - minmaxLeft.second), abs(root->val - minmaxRight.second)));

		return { tripleMin(minmaxLeft.first, minmaxRight.first, root->val), tripleMax(minmaxLeft.second, minmaxRight.second, root->val) };
	}

public:
	int maxAncestorDiff(TreeNode* root) {
		int ans = 0;
		dfs(root, ans);
		return ans;
	}
};
// @lc code=end
