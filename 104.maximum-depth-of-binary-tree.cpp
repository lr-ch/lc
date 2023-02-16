/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
class SolutionDFS {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		int left = maxDepth(root->left) + 1;
		int right = maxDepth(root->right) + 1;
		return max(left, right);
	}
};

class SolutionBFS {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;

		queue<TreeNode *> q;
		q.push(root);

		int max = 0;
		while (!q.empty()) {
			int qsize = q.size();
			max++;
			while (qsize--) {
				auto node = q.front();
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return max;
	}
};

class Solution {
	/*
	 * Accepted
	 *  * 39/39 cases passed (7 ms)
	 *  * Your runtime beats 83.96 % of cpp submissions
	 *  * Your memory usage beats 99.7 % of cpp submissions (18.7 MB)
	 */
	SolutionDFS dfs;

	/*
	 * Accepted
	 *  * 39/39 cases passed (7 ms)
	 *  * Your runtime beats 83.96 % of cpp submissions
	 *  * Your memory usage beats 19.79 % of cpp submissions (19.1 MB)
	 */
	SolutionBFS bfs;
public:
	int maxDepth(TreeNode* root) {
	//	return dfs.maxDepth(root);
		return bfs.maxDepth(root);
	}
};
// @lc code=end