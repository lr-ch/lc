/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		// corner cases
		//  only 1 node
		if (n == 1) return { 0 };
		//  only 2 nodes
		if (n == 2) return { 0, 1 };

		// index - node_i, vector<int> - node_[0..n] connected to node_i
		vector<vector<int>> adj_matrix(n);
		// index - nide_i, value - number of nodes connected to node_i
		vector<int> degree(n);

		// initial the matrix and table
		for (auto& e : edges) {
			int node_i = e[0], node_j = e[1];
			adj_matrix[node_i].push_back(node_j);
			adj_matrix[node_j].push_back(node_i);
			degree[node_i]++;
			degree[node_j]++;
		}

		// select leaf to trim
		queue<int> leaf_to_trim;
		for (int i = 0; i < n; i++)
			if (degree[i] == 1)
				leaf_to_trim.push(i);

		// the leaf number could only be 1 or 2, so stop trimming when n <= 2
		while (n > 2) {
			// beacuse the queue content will change in for-loop later, must save the size here
			int leaf_number = leaf_to_trim.size();
			// now trim off all leaves
			while (leaf_number--) {
				// decrease the degree of leaf
				int leaf = leaf_to_trim.front();
				leaf_to_trim.pop();
				degree[leaf]--;
				n--;	// don't forget to decease total nodes number

				// search for connections of the leaf (BFS)
				for (int& leaf_neighbor : adj_matrix[leaf]) {
					// decrease the degree of leaf beighbor as well (because the leaf is trimmed off)
					degree[leaf_neighbor]--;
					// if it is leaf now, add this neightbor to queue for next round trimming
					if (degree[leaf_neighbor] == 1)
						leaf_to_trim.push(leaf_neighbor);
				}
			}
		}

		vector<int> ans;
		// the last round trimming queue is the answer
		while(!leaf_to_trim.empty()) {
			ans.push_back(leaf_to_trim.front());
			leaf_to_trim.pop();
		}

		return ans;
	}
};
// @lc code=end

