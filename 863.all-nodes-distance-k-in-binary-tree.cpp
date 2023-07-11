/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
	void buildAdjs(TreeNode* parent, TreeNode* current) {
		if (parent && current) {
			adjs[parent->val].push_back(current->val);
			adjs[current->val].push_back(parent->val);
		}

		if (current && current->left)
			buildAdjs(current, current->left);

		if (current && current->right)
			buildAdjs(current, current->right);
	}

	unordered_map<int, vector<int>> adjs;
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		buildAdjs(nullptr, root);

		queue<int> q;
		q.push(target->val);
		vector<bool> v(500, false);
		v[target->val] = true;

		vector<int> ans;
		while (!q.empty() && k >= 0) {
			if (k == 0) {
				while (!q.empty()) {
					ans.push_back(q.front());
					q.pop();
				}
				return ans;
			}

			int qsize = q.size();
			while (qsize--) {
				int node = q.front(); q.pop();
				v[node] = true;
				for (const auto& next : adjs[node])
					if (!v[next]) q.push(next);
			}

			k--;
		}

		return ans;
	}
};
// @lc code=end
