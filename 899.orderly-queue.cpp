/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
public:
	string orderlyQueue(string s, int k) {
		string ans = s;

		if (k == 1) {
			for (int i = 0; i < s.length(); i++) {
				s = s.substr(1, s.length() - 1) + s[0];
				if (s < ans)
					ans = s;
			}
		} else
			sort(ans.begin(), ans.end());

		return ans;
	}
};
// @lc code=end

