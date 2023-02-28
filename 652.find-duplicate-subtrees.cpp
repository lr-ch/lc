/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
	string traverse(TreeNode* root) {
		if (!root) return string("$");

		string curr = "(" + traverse(root->left) + ")" +
							to_string(root->val) +
					  "(" + traverse(root->right) + ")";
		paths[curr]++;
		if (paths[curr] == 2) ans.push_back(root);
		return curr;
	}

	unordered_map<string, int> paths;
	vector<TreeNode*> ans;
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		traverse(root);
		return ans;
	}
};
// @lc code=end
