/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class SolutionBFS {
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

class SolutionUF {
	struct UnionFind {
		int groups;
		vector<int> boss;

		UnionFind(int n) : groups(n) {
			boss.resize(n);
			iota(boss.begin(), boss.end(), 0);
		}

		int find(int x) {
			while (boss[x] != x) {
				boss[x] = boss[boss[x]];
				x = boss[x];
			}
			return boss[x];
		}

		bool unite(int p, int c) {
			int bossP = find(p);    // boss of parent
			int bossC = find(c);    // boss of child

			// e.g.
			//     2   0
			//      \ /
			//       1
			if (bossC != c) return false;

			if (bossP != bossC) {
				boss[bossC] = bossP;

				groups--;
				return true;
			}
			return false;
		}
	};

public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		UnionFind uf(n);
		for (int i = 0; i < n; i++) {
			if (leftChild[i] != -1)
				if (!uf.unite(i, leftChild[i])) return false;

			if (rightChild[i] != -1)
				if (!uf.unite(i, rightChild[i])) return false;
		}
		return uf.groups == 1;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 44/44 cases passed (38 ms)
	 *  - Your runtime beats 63.22 % of cpp submissions
	 *  - Your memory usage beats 44.22 % of cpp submissions (36.8 MB)
	 */
	SolutionBFS bfs;

	/*
	 * Accepted
	 *  - 44/44 cases passed (35 ms)
	 *  - Your runtime beats 72.95 % of cpp submissions
	 *  - Your memory usage beats 92.71 % of cpp submissions (32.3 MB)
	 */
	SolutionUF uf;
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
	//	return bfs.validateBinaryTreeNodes(n, leftChild, rightChild);
		return uf.validateBinaryTreeNodes(n, leftChild, rightChild);
	}
};
// @lc code=end
