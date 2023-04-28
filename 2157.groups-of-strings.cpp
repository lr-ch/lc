/*
 * @lc app=leetcode id=2157 lang=cpp
 *
 * [2157] Groups of Strings
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss, gang_size;
		int groups;

		UnionSet(int n)
			: boss(n), gang_size(n, 1), groups(n)
		{
			iota(boss.begin(), boss.end(), 0);
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
				if (bossX < bossY) {
					boss[bossY] = bossX;
					gang_size[bossX] += gang_size[bossY];
				} else {
					boss[bossX] = bossY;
					gang_size[bossY] += gang_size[bossX];
				}
				groups--;
			}
		}
	};

public:
	vector<int> groupStrings(vector<string>& words) {
		UnionSet us(words.size());

		unordered_map<bitset<26>, int> hash_to_index, hash_to_index2;
		for (int i = 0; i < words.size(); i++) {
			bitset<26> hash;
			for (const auto& ch : words[i]) hash.set(ch - 'a');

			// same word
			if (hash_to_index.count(hash)) us.unite(i, hash_to_index[hash]);

			// add/del one character
			for (int j = 0; j < 26; j++) {
				hash.flip(j);
				if (hash_to_index.count(hash)) us.unite(i, hash_to_index[hash]);
				hash.flip(j);
			}

			// replace only one character
			for (int k = 0; k < 26; k++)
				if (hash.test(k)) {
					hash.flip(k);
					if (hash_to_index2.count(hash)) us.unite(i, hash_to_index2[hash]);
					hash_to_index2[hash] = i;
					hash.flip(k);
				}

			hash_to_index[hash] = i;
		}

		return { us.groups, *max_element(us.gang_size.begin(), us.gang_size.end()) };
	}
};
// @lc code=end
