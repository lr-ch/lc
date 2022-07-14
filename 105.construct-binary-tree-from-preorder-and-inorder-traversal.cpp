/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
	TreeNode* arrayToTree(vector<int>& p, vector<int>& i, int pi,
							map<int, int>& is, int left, int right)
	{
		if (right < left) return nullptr;

		TreeNode *root = new TreeNode(p[pi]);
		int inorderIndex = is[p[pi]];

		root->left = arrayToTree(p, i, pi + 1, is, left, inorderIndex - 1);
		root->right = arrayToTree(p, i, pi + inorderIndex - left + 1, is, inorderIndex + 1, right);

		return root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// create a map for inorder, value->index
		map<int, int> inorder_seq;
		for (int i = 0; i < inorder.size(); i++)
			inorder_seq.insert({inorder[i], i});	// <value, index>

		int preorderIndex = 0;
		return arrayToTree(preorder, inorder, preorderIndex,
							inorder_seq, 0, inorder.size() - 1);
	}
};
// @lc code=end

