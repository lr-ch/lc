/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
	int maxScore(string s) {
		/*
		 * score = Zero_left + One_right
		 *       = Zero_left + (One_total - One_left)
		 * => max(score) = max(Zero_left - One_left) + One_total
		 */

		int one_total = 0, zero_total = 0, best_diff = INT_MIN;
		for (int i = 0; i < s.length() - 1; i++) {
			switch (s[i]) {
				case '1' :
					one_total++;
					break;
				case '0' :
					zero_total++;
					break;
			}

			best_diff = max(best_diff, zero_total - one_total);
		}

		if (s.back() == '1') one_total++;
		return best_diff + one_total;
	}
};
// @lc code=end
