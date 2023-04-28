/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;
		int groups;

		UnionSet(int n) {
			boss.resize(n);
			for (int i = 0; i < n; i++) boss[i] = i;
			groups = n;
		}

		int find(int i) {
			while (boss[i] != i) {
				boss[i] = boss[boss[i]];
				i = boss[i];
			}
			return boss[i];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				boss[bossX] = bossY;
				groups--;
			}
		}
	};

	bool isSimiliar(string_view s1, string_view s2) {
		int count = 0;

		// s1 and s2 are anagrams to each other
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) count++;
			if (count > 2) break;
		}
		return count == 0 || count == 2;
	}

public:
	int numSimilarGroups(vector<string>& strs) {
		UnionSet us(strs.size());

		for (int i = 0; i < strs.size(); i++)
			for (int j = i + 1; j < strs.size(); j++)
				if (isSimiliar(strs[i], strs[j]))
					us.unite(i, j);

		return us.groups;
	}
};
// @lc code=end
