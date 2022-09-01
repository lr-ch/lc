/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
class SolutionVector {
	void traverse (TreeNode* root, vector<int>& path, int& ans) {
		if (!root) return;

		path.push_back(root->val);
		auto iter = max_element(path.begin(), path.end());
		if (*iter <= root->val) ans++;

		traverse(root->left, path, ans);
		traverse(root->right, path, ans);

		path.pop_back();
	}

public:
	int goodNodes(TreeNode* root) {
		vector<int> path;
		int ans = 0;
		traverse(root, path, ans);
		return ans;
	}
};

class SolutionWithParamter {
	void traverse(TreeNode* root, int m, int& ans) {
		if (!root) return;

		if (root->val >= m) {
			ans++;
			m = root->val;
		}

		traverse(root->left, m, ans);
		traverse(root->right, m, ans);
	}

public:
	int goodNodes(TreeNode* root) {
		int max_node = INT_MIN, ans = 0;
		traverse(root, max_node, ans);
		return ans;
	}
};

class Solution {
	int traverse(TreeNode* root, int m) {
		if (!root) return 0;

		if (root->val >= m)
			return 1 + traverse(root->left, root->val) + traverse(root->right, root->val);
		else
			return traverse(root->left, m) + traverse(root->right, m);
	}

public:
	int goodNodes(TreeNode* root) {
		return traverse(root, INT_MIN);
	}
};
// @lc code=end
