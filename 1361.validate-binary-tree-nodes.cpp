/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class Solution {
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<int> ind(n, 0);
		for (int i = 0; i < n; i++) {
			if (-1 != leftChild[i]) ind[leftChild[i]]++;
			if (-1 != rightChild[i]) ind[rightChild[i]]++;
		}

		queue<int> q;
		unordered_set<int> v;	// visted nodes

		// search for tree root
		for (int i = 0; i < n; i++)
			if (ind[i] == 0) {
				q.push(i);
				break;
			}

		while (!q.empty()) {
			auto node = q.front(); q.pop();
			if (v.count(node)) return false;	// loop detected
			v.insert(node);

			// continue to subtrees
			if (-1 != leftChild[node]) q.push(leftChild[node]);
			if (-1 != rightChild[node]) q.push(rightChild[node]);
		}

		return v.size() == n;	// every node should be visited only once
	}
};
// @lc code=end
