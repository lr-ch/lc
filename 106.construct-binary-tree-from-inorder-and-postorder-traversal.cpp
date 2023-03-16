/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
		TreeNode* arrayToTree(vector<int>& in, vector<int>& post, int is, int ie, int ps, int pe) {
			if (is > ie || ps > pe) return nullptr;

			TreeNode* root = new TreeNode(post[pe]);

			int mid = inorder_dict[post[pe]];
			int ltree_size = mid - is;

			root->left = arrayToTree(in, post, is, mid - 1, ps, ps + ltree_size - 1);
			root->right = arrayToTree(in, post, mid + 1, ie, ps + ltree_size, pe - 1);

			return root;
		}

		unordered_map<int, int> inorder_dict;
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		// create a dict for inorder, query by value and return its index
		for (int i = 0; i < inorder.size(); i++)
			inorder_dict.insert({inorder[i], i});

		return arrayToTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
};
// @lc code=end
