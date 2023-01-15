/*
 * @lc app=leetcode id=2421 lang=cpp
 *
 * [2421] Number of Good Paths
 */

// @lc code=start
class SolutionTLE {
	void dfs(vector<vector<int>>& t, vector<int>& vs, int start, int node, vector<bool>& v) {
		// bad path
		if (vs[node] > vs[start]) return;

		// good path
		if (start != node && vs[node] == vs[start]) paths++;

		// continuing search
		v[node] = true;
		for (const auto& child : t[node]) {
			if (v[child]) continue;
			dfs(t, vs, start, child, v);
		}
		v[node] = false;

		return;
	}

	int N, paths;
public:
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
		N = vals.size();
		paths = 0;

		vector<vector<int>> tree(N);
		for (const auto& e : edges) {
			tree[e[0]].push_back(e[1]);
			tree[e[1]].push_back(e[0]);
		}

		vector<bool> visited(N);
		for (int i = 0; i < N; i++)
			dfs(tree, vals, i, i, visited);

		// every node + paths(forward + revered)
		return N + paths / 2;
	}
};

class Solution {
	struct UnionSet {
		vector<int> boss;

		UnionSet(int n) {
			boss.resize(n);
			iota(boss.begin(), boss.end(), 0);
		}

		int Find(int x) {
			while (boss[x] != x) {
				x = boss[x];
				boss[x] = boss[boss[x]];
			}
			return x;
		}

		void Unite(int x, int y) {
			boss[x] = y;
		}
	};

	int N, ans;
public:
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
		N = vals.size();
		ans = N;	// every node itself is a good path

		UnionSet us(N);

		vector<pair<int, int>> val_paths;
		for (int i = 0; i < N; i++)
			val_paths.push_back({ vals[i], 1 });

		sort(edges.begin(), edges.end(), [&](const auto& a, const auto& b) {
			return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
		});

		for (const auto& e : edges) {
			int x = us.Find(e[0]), y = us.Find(e[1]);
			if (val_paths[x].first == val_paths[y].first) {
				us.Unite(x, y);

				ans += val_paths[x].second * val_paths[y].second;
				val_paths[y].second += val_paths[x].second;
			} else if (val_paths[x].first > val_paths[y].first)
				us.Unite(y, x);
			else
				us.Unite(x, y);
		}
		return ans;
	}
};
// @lc code=end
