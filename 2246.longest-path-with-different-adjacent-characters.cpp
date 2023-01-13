/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& t, string& s, int node) {
		/*
		 * every node has at least length 1, but only node has two or more children could have maxlen2 > 0
		 * e.g.1                     e.g.2                    e.g.3
		 *    a    => maxlen1 = 2,     a    => maxlen1 = 2,     a    => maxlen1 = 1,
		 *   / \      maxlen2 = 2     /        maxlen2 = 0              maxlen2 = 0
		 *  b   c                    b
		 */
		int maxlen1 = 1, maxlen2 = 0;
		for (const int child : t[node]) {
			int len = dfs(t, s, child);

			if (s[child] == s[node]) continue;

			if (len > maxlen1) {
				maxlen2 = maxlen1;
				maxlen1 = len;
			} else if (len > maxlen2) {
				maxlen2 = len;
			}
		}

		// if maxlen2 > 0, the node (root) length is counted twice, so it shall decrease 1
		// see e.g.1 above
		ans = max(ans, maxlen1 + (maxlen2 == 0 ? 0 : maxlen2 - 1));

		return maxlen1 + 1;
	}

	int ans;
public:
	int longestPath(vector<int>& parent, string s) {
		vector<vector<int>> tree(parent.size());
		for (int i = 1; i < parent.size(); i++)
			tree[parent[i]].push_back(i);

		dfs(tree, s, 0);

		return ans;
	}
};
// @lc code=end
