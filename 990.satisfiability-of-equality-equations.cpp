/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class Solution {
	struct UnionFind {
		array<char, 26> boss;

		UnionFind() {
			for (char c = 'a'; c <= 'z'; c++) boss[c - 'a'] = c;
		}

		void unite(char a, char b) {
			char bossA = find(a);
			char bossB = find(b);

			if (bossA == bossB) return;

			if (bossA > bossB) {
				boss[b - 'a'] = bossA;
				boss[bossB - 'a'] = bossA;
			} else {
				boss[a - 'a'] = bossB;
				boss[bossA - 'a'] = bossB;
			}
		}

		char find(char ch) {
			while (boss[ch - 'a'] != ch) {
				boss[ch - 'a'] = boss[boss[ch - 'a'] - 'a'];
				ch = boss[ch - 'a'];
			}
			return ch;
		}

		void dump() {
			for (auto& c : boss) cout << c;
		}
	};

public:
	bool equationsPossible(vector<string>& equations) {
		UnionFind uf;
		for (auto& str : equations)
			if (str[1] == '=') uf.unite(str[0], str[3]);

	//	uf.dump();

		for (auto& str : equations)
			if (str[1] == '!' && uf.find(str[0]) == uf.find(str[3]))
				return false;

		return true;
	}
};
// @lc code=end
