/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
	void dfs(Node* root, vector<vector<int>>& nodes, int level) {
		if (!root) return;

		if (nodes.size() <= level)
			nodes.push_back({ root->val });
		else
			nodes[level].push_back(root->val);

		for (int i = 0; i < root->children.size(); i++)
			dfs(root->children[i], nodes, level + 1);
	}

public:
	vector<vector<int>> levelOrder(Node* root) {
		if (!root) return {};

		vector<vector<int>> ans(1, vector<int>{});
		dfs(root, ans, 0);
		return ans;
	}
};
// @lc code=end
