/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
	int widthOfBinaryTree(TreeNode* root) {
		/*
		 *                                                   1
		 *    i       node index encoding rule       e.g.   / \
		 *   / \   => left child  : j = i * 2              2   3
		 *  j   k     right child : k = i * 2 + 1         / \ / \
		 *                                               4  5 6  7 ...
		 */

		queue<pair<TreeNode *, uint64_t>> q;		// <node, index>
		uint64_t res = 1;

		if (root) q.push({root, 0});
		while (!q.empty()) {
			int qsize = q.size();
			res = max(res, q.back().second - q.front().second + 1);

			while (qsize--) {
				const auto [node, index] = q.front(); q.pop();
				if (node->left)
					q.push({node->left, index * 2});
				if (node->right)
					q.push({node->right, index * 2 + 1});
			}
		}

		return (int)res;
	}
};
// @lc code=end
