/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
	char findTheDifference(string s, string t) {
		sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        auto iters = s.begin(), itert = t.begin();
        while (iters != s.end()) {
            if (*iters != *itert)
                return *itert;
            iters++; itert++;
        }
        return *itert;
	}
};
// @lc code=end
