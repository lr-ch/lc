/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
	vector<TreeNode*> allPossibleFBT(int n) {
		/* base cases
		 *   n = 1    n = 3
		 *     1        1
		 *             / \
		 *            2   3
		 */
		if (n == 1) return {new TreeNode()};
		if (n < 3) return {};

		vector<TreeNode *> res;
		for (int i = 1; i < n; i += 2)
			for (const auto& left : allPossibleFBT(i))
				for (const auto& right : allPossibleFBT(n - i - 1))
					res.emplace_back(new TreeNode(0, left, right));

		return res;
	}
};
// @lc code=end
