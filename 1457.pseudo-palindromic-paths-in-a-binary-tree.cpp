/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
	bool countCheck(array<int, 10>& c) {
		int odd = 0;
		for (auto& i : c)
			if (i % 2) odd++;
		return odd <= 1;
	}

	void traverse(TreeNode* root, array<int, 10>& c, int& r) {
		if (!root) return;

		// only check path at leaf node, which means no left&right children
		if (!root->left && !root->right) {
			c[root->val]++;
			if (countCheck(c)) r++;
			c[root->val]--;
			return;
		}

		c[root->val]++;
		traverse(root->left, c, r);
		traverse(root->right, c, r);
		c[root->val]--;
	}

public:
	int pseudoPalindromicPaths (TreeNode* root) {
		array<int, 10> count;	// 1 <= node.val <= 9
		int result = 0;

		fill(count.begin(), count.end(), 0);
		traverse(root, count, result);
		return result;
	}
};
// @lc code=end
