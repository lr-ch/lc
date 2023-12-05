/*
 * @lc app=leetcode id=1688 lang=cpp
 *
 * [1688] Count of Matches in Tournament
 */

// @lc code=start
class Solution {
public:
	int numberOfMatches(int n) {
		int ans = 0;
		while (n != 1) {
			if (n % 2) ans++;
			ans += (n /= 2);
		}
		return ans;
	}
};
// @lc code=end

