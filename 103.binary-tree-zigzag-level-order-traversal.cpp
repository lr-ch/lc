/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root) return {};

		vector<vector<int>> ans;
		queue<TreeNode *> q;
		q.push(root);
		bool invert = false;

		while (!q.empty()) {
			int qsize = q.size();
			vector<int> level;
			while (qsize--) {
				TreeNode *curr = q.front(); q.pop();
				if (!curr) continue;

				level.push_back(curr->val);
				q.push(curr->left);
				q.push(curr->right);
			}
			if (invert) reverse(level.begin(), level.end());
			if (!level.empty()) ans.push_back(level);

			invert = !invert;
			level.clear();
		}

		return ans;
	}
};
// @lc code=end
