/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
	void travel(TreeNode* r, vector<int>& ans, int lvl) {
		if (r == nullptr) return;

		// since we go right node then go left, right node are
		// always put prior than left node
		if (ans.size() == lvl)
			ans.push_back(r->val);

		travel(r->right, ans, lvl + 1);
		travel(r->left, ans, lvl + 1);

		return;
	}

public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		travel(root, ans, 0);
		return ans;
	}
};
// @lc code=end

