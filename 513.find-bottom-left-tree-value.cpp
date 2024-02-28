/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
	int max_level = INT_MIN, leftmost_value;
public:
	int findBottomLeftValue(TreeNode* root, int level = 0) {
		if (!root) return 0;

		if (level > max_level) {
			max_level = level;
			leftmost_value = root->val;
		}

		findBottomLeftValue(root->left, level + 1);
		findBottomLeftValue(root->right, level + 1);

		return leftmost_value;
	}
};
// @lc code=end
