/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<char> boss;

		UnionSet() {
			boss.resize(26);
			for (int i = 0; i < 26; i++) boss[i] = 'a' + i;
		}

		char find(char a) {
			while (boss[a - 'a'] != a) {
				a = boss[a - 'a'];
				boss[a - 'a'] = boss[boss[a - 'a'] - 'a'];
			}
			return a;
		}

		void Unite(char a, char b) {
			char bossA = find(a);
			char bossB = find(b);

			if (bossA > bossB) boss[bossA - 'a'] = boss[bossB - 'a'];
			else boss[bossB - 'a'] = bossA;
		}
	};

public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		UnionSet us;

		for (int i = 0; i < s1.size(); i++)
			us.Unite(s1[i], s2[i]);

		string ans;
		for (const char ch : baseStr)
			ans += us.find(ch);

		return ans;
	}
};
// @lc code=end
