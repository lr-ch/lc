/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
	void traverse(TreeNode* r, vector<int>& v) {
		if (!r->right && !r->left) {
			v.push_back(r->val);
			return;
		}

		if (r->left) traverse(r->left, v);
		if (r->right) traverse(r->right, v);
	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> s1, s2;
		traverse(root1, s1);
		traverse(root2, s2);
		return s1 == s2;
	}
};
// @lc code=end

