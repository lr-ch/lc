/*
 * @lc app=leetcode id=2709 lang=cpp
 *
 * [2709] Greatest Common Divisor Traversal
 */

// @lc code=start

class Solution {
	struct UnionFind {
		/*        nums            primes
		 *  +-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
		 *  |0|1|........n| |2|3|5|7|......P|
		 *  +-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
		 *
		 *                boss
		 *  +-+-+-+-+-+-+-+---+-+-+-+-+-+-+--+
		 *  |0|1|........n| 0 |1|.........|Pn|
		 *  +-+-+-+-+-+-+-+---+-+-+-+-+-+-+--+
		 *
		 *  e.g. boss[i], i < n -> boss of nums[i]
		 *       boss[j], j >= n -> boss of primes[j - n]
		 *  if primes[j - n] is a factor of nums[i], boss[j] is i
		 *     primes[j - n] is also a factor nums[k], boss of nums[k] will also be i
		 *
		 *  Unite all boss[i] and boss[j], check whether the groups reduces to 1
		 */
		vector<int> boss;
		int groups;
		int N, P;

		UnionFind(int n, int p)
			: boss(n + p), groups(n), N(n), P(p) {
				iota(boss.begin(), boss.begin() + n, 0);
				iota(boss.begin() + n, boss.end(), n);
			}

		int find(int x) {
			while (boss[x] != x) {
				boss[x] = boss[boss[x]];
				x = boss[x];
			}
			return x;
		}

		void unite(int x, int y) {
			int bossX = find(x), bossY = find(y);
			if (bossX != bossY) {
				if (bossX < bossY) {
					boss[bossY] = bossX;
					if (bossY < N) groups--;
				} else {
					boss[bossX] = bossY;
					if (bossX < N) groups--;
				}
			}
		}
	};

	vector<int> GenPrimes(int n) {
		vector<int> q(n + 1, 0);
		vector<int> primes;
		for (int i = 2; i <= sqrt(n); i++) {
			if (q[i] == 1) continue;

			int j = i * 2;
			while (j <= n) {
				q[j] = 1;
				j += i;
			}
		}
		for (int i = 2; i <= n; i++)
			if (q[i] == 0)
				primes.push_back(i);
		return primes;
	}

public:
	bool canTraverseAllPairs(vector<int>& nums) {
		int maxi = *max_element(nums.begin(), nums.end());
		vector<int> primes = GenPrimes(maxi);

		unordered_map<int, int> indice;
		for (int i = 0; i < primes.size(); i++)
			indice[primes[i]] = i;

		UnionFind uf(nums.size(), primes.size());

		for (int i = 0; i < nums.size(); i++)
			for (int j = 0; j < primes.size(); j++) {
				if (primes[j] > nums[i]) break;

				if (primes[j] * primes[j] > nums[i]) {
					uf.unite(i, nums.size() + indice[nums[i]]);
					break;
				}

				if (nums[i] % primes[j] == 0) {
					uf.unite(i, nums.size() + j);
					while (nums[i] % primes[j] == 0)
						nums[i] /= primes[j];
				}
			}

		return uf.groups == 1;
	}
};
// @lc code=end
