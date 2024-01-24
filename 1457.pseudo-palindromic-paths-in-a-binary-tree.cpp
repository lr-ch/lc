/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
class Solution1 {
	bool countCheck(array<int, 10>& c) {
		int odd = 0;
		for (auto& i : c)
			if (i % 2) odd++;
		return odd <= 1;
	}

	void traverse(TreeNode* root, array<int, 10>& c, int& r) {
		if (!root) return;

		// only check path at leaf node, which means no left&right children
		if (!root->left && !root->right) {
			c[root->val]++;
			if (countCheck(c)) r++;
			c[root->val]--;
			return;
		}

		c[root->val]++;
		traverse(root->left, c, r);
		traverse(root->right, c, r);
		c[root->val]--;
	}

public:
	int pseudoPalindromicPaths (TreeNode* root) {
		array<int, 10> count;	// 1 <= node.val <= 9
		int result = 0;

		fill(count.begin(), count.end(), 0);
		traverse(root, count, result);
		return result;
	}
};

class Solution {
	void preorder(TreeNode* root, bitset<10>& path, int& count) {
		if (root) {
			path[root->val].flip();

			if (!root->left && !root->right)
				if (path.count() <= 1)	// palindrome only accepts odd count is 1 or 0
					count++;			// e.g. "12321", "123321"

			preorder(root->left, path, count);
			preorder(root->right, path, count);

			path[root->val].flip();
		}
	}
public:
	int pseudoPalindromicPaths (TreeNode* root) {
		bitset<10> freq;	// 1 <= Node.val <= 9, the bit will be reset when count to even
		int result = 0;

		preorder(root, freq, result);
		return result;
	}
};
// @lc code=end
