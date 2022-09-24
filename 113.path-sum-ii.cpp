/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
	void traverse(TreeNode* root, vector<int>& path) {
		if (!root) return;

		if (!root->left && !root->right) {
			path.push_back(root->val);
			if (accumulate(path.begin(), path.end(), 0) == target)
				ans.push_back(path);
			path.pop_back();
			return;
		}

		path.push_back(root->val);
		if (root->left) traverse(root->left, path);
		if (root->right) traverse(root->right, path);
		path.pop_back();
	}

	vector<vector<int>> ans;
	int target;
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		target = targetSum;
		vector<int> path;
		traverse(root, path);
		return ans;
	}
};
// @lc code=end
