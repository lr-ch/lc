/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *  - 14/41 cases passed (N/A)
 *  - Testcase
 *     - 850
 */
class SolutionTLE {
	double prob(int A, int B) {
		if (A <= 0 && B > 0) return 1.0;	// A becomes empty first
		if (A <= 0 && B <= 0) return 0.5;	// A & B become empty at the same time
		if (B <= 0) return 0;				// B becomes empty first

		return 0.25 * (
					prob(A - 100, B) +
					prob(A - 75, B - 25) +
					prob(A - 50, B - 50) +
					prob(A - 25, B - 75));
	}

public:
	double soupServings(int n) {
		return prob(n, n);
	}
};

/*
 * Runtime Error
 *  - 20/41 cases passed (N/A)
 *  - Testcase
 *     - 660295675
 */
class SolutionRE {
	double prob(int A, int B) {
		if (A <= 0 && B > 0) return 1.0;	// A becomes empty first
		if (A <= 0 && B <= 0) return 0.5;	// A & B become empty at the same time
		if (B <= 0) return 0;				// B becomes empty first

		if (dp[A].count(B)) return dp[A][B];

		return dp[A][B] = 0.25 * (
							prob(A - 100, B) +
							prob(A - 75, B - 25) +
							prob(A - 50, B - 50) +
							prob(A - 25, B - 75));
	}

	unordered_map<int, unordered_map<int, double>> dp;
public:
	double soupServings(int n) {
		return prob(n, n);
	}
};

class Solution {
	double prob(int A, int B) {
		if (A <= 0 && B > 0) return 1.0;	// A becomes empty first
		if (A <= 0 && B <= 0) return 0.5;	// A & B become empty at the same time
		if (B <= 0) return 0;				// B becomes empty first

		if (dp[A].count(B)) return dp[A][B];

		return dp[A][B] = 0.25 * (
							prob(A - 100, B) +
							prob(A - 75, B - 25) +
							prob(A - 50, B - 50) +
							prob(A - 25, B - 75));
	}

	unordered_map<int, unordered_map<int, double>> dp;
	const int MAGIC_NUM = 4850;
public:
	double soupServings(int n) {
		// when n is big enough, the probability will be close to 1.0
		if (n >= MAGIC_NUM) return 1.0;
		return prob(n, n);
	}
};
// @lc code=end
