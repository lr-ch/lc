/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
	TreeNode* dfs(vector<int>& n, int left, int right) {
		if (left > right) return nullptr;

		int mid = left + (right - left) / 2;
		TreeNode *root = new TreeNode(n[mid]);
		root->left = dfs(n, left, mid - 1);
		root->right = dfs(n, mid + 1, right);
		return root;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return dfs(nums, 0, nums.size() - 1);
	}
};
// @lc code=end
