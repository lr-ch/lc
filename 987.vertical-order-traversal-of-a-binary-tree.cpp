/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
	struct node {
		int val;
		int row;
		int col;
		node(int v, int r, int c) :
			val(v), row(r), col(c) {}
		~node() {}
	};

	void traverse(TreeNode* r, map<int, vector<node>>& treeMap, int row, int col) {
		if (!r) return;

		treeMap[col].push_back(node(r->val, row, col));
		traverse(r->left, treeMap, row + 1, col - 1);
		traverse(r->right, treeMap, row + 1, col + 1);
	}
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int, vector<node>> verTree;	// <column, values at the column>
		vector<vector<int>> ans;
		traverse(root, verTree, 0, 0);
		for (auto& i : verTree) {
			sort(i.second.begin(), i.second.end(), [](const auto& a, const auto& b) {
				if (a.row == b.row) {
					if (a.col == b.col) return a.val < b.val;
					return a.col < b.col;
				}
				return a.row < b.row;
			});

			vector<int> tmp;
			for (auto& a : i.second)
				tmp.push_back(a.val);
			ans.push_back(tmp);
		}
		return ans;
	}
};
// @lc code=end

