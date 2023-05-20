/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
	struct UnionSet {
		unordered_map<string, pair<string, double>> boss;

		UnionSet() {}

		pair<string, double> find(const string& S) {
			if (S != boss[S].first) {
				auto [bossS, ratioS] = find(boss[S].first);
				boss[S].first = bossS;
				boss[S].second *= ratioS;
			}
			return boss[S];
		}

		void unite(const string& X, const string& Y, double Ratio) {
			// e.g. [ "x", "y" ] = [ 2.0 ]
			// x = 2.0 * y
			// y = 1.0 * y
			if (boss.count(X) == 0 && boss.count(Y) == 0) {
				boss[X] = { Y, Ratio };
				boss[Y] = { Y, 1.0 };
			} else if (boss.count(X) == 0) {
				boss[X] = { Y, Ratio };
			} else if (boss.count(Y) == 0) {
				boss[Y] = { X, 1.0 / Ratio };
			} else {
				auto [bossX, ratioX] = find(X);
				auto [bossY, ratioY] = find(Y);
				boss[bossX] = { bossY, Ratio / ratioX * ratioY };
			}
		}
	};

public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		UnionSet us;

		// init UnionSet
		for (int i = 0; i < equations.size(); i++) {
			const string& x = equations[i][0];
			const string& y = equations[i][1];
			const double& r = values[i];
			us.unite(x, y, r);
		}

		// calculate
		vector<double> ans;
		for (const auto& q : queries) {
			const string& A = q[0];
			const string& B = q[1];

			if (us.boss.count(A) == 0 || us.boss.count(B) == 0) {
				ans.push_back(-1.0);
				continue;
			}

			const auto [bossA, ratioA] = us.find(A);
			const auto [bossB, ratioB] = us.find(B);
			if (bossA != bossB)
				ans.push_back(-1);
			else
				ans.push_back(ratioA / ratioB);
		}
		return ans;
	}
};
// @lc code=end
