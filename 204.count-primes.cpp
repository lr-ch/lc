/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
	int countPrimes(int n) {
		if (n == 0 || n == 1) return 0;
		vector<bool> isPrime(n, true);

		int count = 0;
		for (int i = 2; i < n; i++) {
			if (isPrime[i]) {
				count++;
				for (int j = i * 2; j < n; j += i)
					isPrime[j] = false;
			}
		}
		return count;
	}
};
// @lc code=end
