/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
class SolutionBFS {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;

		queue<TreeNode *> q;
		q.push(root);

		int count = 0;
		while (!q.empty()) {
			int qsize = q.size();
			for (int i = 0; i < q.size(); i++) {
				TreeNode *node = q.front();
				q.pop();
				count++;

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return count;
	}
};

class SolutionOpt {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;

		TreeNode *left = root, *right = root;
		int heightL = 0, heightR = 0;

		while (left) {
			left = left->left;
			heightL++;
		}

		while (right) {
			right = right->right;
			heightR++;
		}

		if (heightL == heightR) return pow(2, heightL) - 1;

		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

class Solution {
	SolutionBFS bfs;
	SolutionOpt opt;
public:
	int countNodes(TreeNode* root) {
	//	return bfs.countNodes(root);
		return opt.countNodes(root);
	}
};
// @lc code=end
