/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
public:
	int maxLevelSum(TreeNode* root) {
		queue<TreeNode *> q;
		q.push(root);

		int maxSum = INT_MIN, ans = 0, level = 0;
		while (!q.empty()) {
			int qsize = q.size(), sum = 0;
			level++;

			while (qsize--) {
				auto node = q.front(); q.pop();
				sum += node->val;

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}

			// update record
			if (sum > maxSum) {
				ans = level;
				maxSum = sum;
			}
		}

		return ans;
	}
};
// @lc code=end
