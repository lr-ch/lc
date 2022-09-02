/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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

/*
 * Accepted
 *  - 66/66 cases passed (14 ms)
 *  - Your runtime beats 93.54 % of cpp submissions
 *  - Your memory usage beats 19.66 % of cpp submissions (22.6 MB)
 */
class SolutionDFS {
	void traverse(TreeNode* root, vector<pair<double, int>>& m, int level) {
		if (!root) return;

		// first time?
		if (m.size() < level) {
			m.push_back({ root->val, 1 });
		} else {
			m[level - 1].first += root->val;
			m[level - 1].second += 1;
		}

		traverse(root->left, m, level + 1);
		traverse(root->right, m, level + 1);
	}

public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<pair<double, int>> memo;
		traverse(root, memo, 1);

		vector<double> ans;
		for (auto& i : memo)
			ans.push_back(i.first / i.second);

		return ans;
	}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode *> nodes;
		vector<double> ans;

		nodes.push(root);

		while (!nodes.empty()) {
			int count = nodes.size();
			double sum = 0;
			for (int i = 0; i < count; i++) {
				// take out the element from queue
				TreeNode *node = nodes.front();
				nodes.pop();

				// accumulate its value
				sum += node->val;

				// store the next level nodes
				if (node->left)
					nodes.push(node->left);
				if (node->right)
					nodes.push(node->right);
			}
			ans.push_back(sum / count);
		}
		return ans;
	}
};
// @lc code=end
