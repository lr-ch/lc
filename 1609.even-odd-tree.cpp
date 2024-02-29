/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
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
	bool isEvenOddTree(TreeNode* root) {
		queue<TreeNode *> q;
		q.push(root);
		bool even = true;

		while (!q.empty()) {
			int qsize = q.size(), prev = even ? INT_MIN : INT_MAX;
			while (qsize--) {
				auto curr = q.front(); q.pop();

				if (even) {
					if ((curr->val % 2 == 0) || (curr->val <= prev)) return false;
				} else {
					if ((curr->val % 2 != 0) || (curr->val >= prev)) return false;
				}

				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
				prev = curr->val;
			}
			even = !even;
		}
		return true;
	}
};
// @lc code=end
