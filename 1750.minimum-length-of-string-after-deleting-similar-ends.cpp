/*
 * @lc app=leetcode id=1750 lang=cpp
 *
 * [1750] Minimum Length of String After Deleting Similar Ends
 */

// @lc code=start
class Solution {
public:
	int minimumLength(string s) {
		auto l = s.begin(), r = s.end() - 1;

		while (l < r && *l == *r) {
			auto ch = *l;

			while (l <= r && ch == *l) l++;
			while (l < r && ch == *r) r--;
		}

		return r - l + 1;
	}
};
// @lc code=end
