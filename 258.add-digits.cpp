/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class SolutionIter {
public:
	int addDigits(int num) {
		int ans = 0;
		do {
			do {
				ans += num % 10;
			} while (num /= 10);

			if (ans < 10) break;

			// reset
			num = ans;
			ans = 0;
		} while (1);

		return ans;
	}
};

class SolutionMath {
public:
	int addDigits(int num) {
		if (0 == num) return 0;

		/*
		 * e.g. Number ABCD
		 *       = 1000A+100B+10C+D = 9 * (111 * A + 11 * B + C) + (A + B + C + D)
		 *       => MOD(9) + (A + B + C + D)
		 */
		else if (0 == num % 9) return 9;
		else return num % 9;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 1101/1101 cases passed (0 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 7.98 % of cpp submissions (6 MB)
	 */
	SolutionIter iter;

	/*
	 * Accepted
	 *  - 1101/1101 cases passed (0 ms)
	 *  - Your runtime beats 100 % of cpp submissions
	 *  - Your memory usage beats 92.24 % of cpp submissions (5.9 MB)
	 */
	SolutionMath math;
public:
	int addDigits(int num) {
	//	return iter.addDigits(num);
		return math.addDigits(num);
	}
};
// @lc code=end
