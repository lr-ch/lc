/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	/*
	 * -- Recursive
	 * Accepted
	 *  * 27/27 cases passed (33 ms)
	 *  * Your runtime beats 87.54 % of cpp submissions
	 *  * Your memory usage beats 12.41 % of cpp submissions (23.3 MB)
	 */
/*
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return root;

		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		if (root == p || root == q) return root;
		if (!left) return right;
		if (!right) return left;

		return root;
	}
*/
	/*
	 * -- Iteration
	 * Accepted
	 *  * 28/28 cases passed (30 ms)
	 *  * Your runtime beats 94.63 % of cpp submissions
	 *  * Your memory usage beats 12.34 % of cpp submissions (23.3 MB)
	 */
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int lo = min(p->val, q->val);
		int hi = max(p->val, q->val);

		while (root->val < lo || root->val > hi)
			root = root->val < lo ? root->right : root->left;

		return root;
	}
};
// @lc code=end

