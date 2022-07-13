/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
	void traverse(TreeNode* root, map<int, pair<int, int>>& m, int level, int parent) {
		if (root == nullptr) return;

		m.insert({root->val, {level, parent}});
		traverse(root->left, m, level + 1, root->val);
		traverse(root->right, m, level + 1, root->val);
	}

public:
	bool isCousins(TreeNode* root, int x, int y) {
		// <node value, node level, parent>>
		map<int, pair<int, int>> value_level;
		traverse(root, value_level, 0, -1);
		return value_level[x].first == value_level[y].first &&
				value_level[x].second != value_level[y].second;
	}
};
// @lc code=end

