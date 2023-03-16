/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
class SolutionGen {
	TreeNode* build(vector<int>& pre, vector<int>& post,
					int preS, int preE, int postS, int postE) {
		if (preS > preE || postS > postE) return nullptr;
		if (preS == preE) return new TreeNode(pre[preS]);

		// pre[preS] -> the value of root
		// pre[preS + 1] -> the value of left-subtree
		int leftTreeSize = post_dict[pre[preS + 1]] - postS + 1;

		TreeNode* root = new TreeNode(pre[preS]);
		root->left = build(pre, post, preS + 1, preS + leftTreeSize,
							postS, post_dict[pre[preS + 1]]);
		root->right = build(pre, post, preS + leftTreeSize + 1, preE,
								post_dict[pre[preS + 1]] + 1, postE - 1);
		return root;
	}

	unordered_map<int, int> post_dict;
public:
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		for (int i = 0; i < postorder.size(); i++)
			post_dict.insert({postorder[i], i});
		return build(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
	}
};

class SolutionDir {
	int preIndex = 0, postIndex = 0;
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		TreeNode* root = new TreeNode(pre[preIndex++]);

		if (root->val != post[postIndex])
			root->left = constructFromPrePost(pre, post);

		if (root->val != post[postIndex])
			root->right = constructFromPrePost(pre,post);

		postIndex++;

		return root;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 306/306 cases passed (11 ms)
	 *  - Your runtime beats 79.36 % of cpp submissions
	 *  - Your memory usage beats 17.11 % of cpp submissions (26.3 MB)
	 */
	SolutionGen gen;

	/*
	 * Accepted
	 *  - 306/306 cases passed (4 ms)
	 *  - Your runtime beats 97.32 % of cpp submissions
	 *  - Your memory usage beats 56.54 % of cpp submissions (25.5 MB)
	 */
	SolutionDir dir;
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
	//	return gen.constructFromPrePost(pre, post);
		return dir.constructFromPrePost(pre, post);
	}
};
// @lc code=end
