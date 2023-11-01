/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
	void dfs(TreeNode* root) {
		if (!root) return;

		freq[root->val]++;
		dfs(root->left);
		dfs(root->right);
	}

	unordered_map<int, int> freq;
public:
	vector<int> findMode(TreeNode* root) {
		dfs(root);
		int maxFreq = 0;
		for (auto& [n, f] : freq)
			maxFreq = max(maxFreq, f);

		vector<int> ans;
		for (auto& [n, f] : freq)
			if (f == maxFreq)
				ans.push_back(n);
		return ans;
	}
};
// @lc code=end
