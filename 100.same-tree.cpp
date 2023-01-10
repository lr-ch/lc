/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
	void bfs(TreeNode* root, vector<int>& v) {
		if (!root) return;

		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				TreeNode *curr = q.front();
				q.pop();

				if (curr) {
					v.push_back(curr->val);

					q.push(curr->left);
					q.push(curr->right);
				} else
					v.push_back(INT_MIN);
			}
		}
	}

public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		vector<int> vp, vq;
		bfs(p, vp);
		bfs(q, vq);

		return vp == vq;
	}
};
// @lc code=end
