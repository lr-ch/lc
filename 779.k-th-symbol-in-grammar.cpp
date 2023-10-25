/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class SolutionRecur {
public:
	int kthGrammar(int n, int k) {
		if (n == 1) return 0;

		int count = 1 << (n - 2);	// count = pow(2, n - 1) / 2
		return k <= count ?
				kthGrammar(n - 1, k) :
				1 - kthGrammar(n - 1, k - count);
	}
};

class SolutionBit {
public:
	int kthGrammar(int n, int k) {
		bitset<32> b(k - 1);
		return b.count() % 2;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 55/55 cases passed (2 ms)
	 *  - Your runtime beats 51.37 % of cpp submissions
	 *  - Your memory usage beats 53.37 % of cpp submissions (6.3 MB)
	 */
	SolutionRecur recur;

	/*
	 * Accepted
	 *  - 55/55 cases passed (0 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 28.86 % of cpp submissions (6.4 MB)
	 */
	SolutionBit bit;
public:
	int kthGrammar(int n, int k) {
	//	return recur.kthGrammar(n, k);
		return bit.kthGrammar(n, k);
	}
};
// @lc code=end
