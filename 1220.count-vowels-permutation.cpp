/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution {
public:
	int countVowelPermutation(int n) {
		long a = 1, e = 1, i = 1, o = 1, u = 1;
		long a2, e2, i2, o2, u2;
		long mod = 1000000007;

		while (--n) {
			a2 = (e + i + u) % mod;	// end with a -> ea, ia, ua
			e2 = (a + i) % mod;		// end with e -> ae, ie
			i2 = (e + o) % mod;		// end with i -> ei, oi
			o2 = i % mod;			// end with o -> io
			u2 = (i + o) % mod;		// end with u -> iu, ou

			a = a2; e = e2; i = i2; o = o2; u = u2;
		}

		return (a + e + i + o + u) % mod;
	}
};
// @lc code=end

