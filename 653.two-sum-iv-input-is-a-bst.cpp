/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
	void traverse(TreeNode* root, vector<int>& v) {
		if (!root) return;

		traverse(root->left, v);
		v.push_back(root->val);
		traverse(root->right, v);
	}

public:
	bool findTarget(TreeNode* root, int k) {
		vector<int> nums;
		traverse(root, nums);

		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum < k) left++;
			else if (sum > k) right--;
			else if (sum == k) return true;
		}
		return false;
	}
};
// @lc code=end

