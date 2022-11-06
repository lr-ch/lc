/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
public:
	string orderlyQueue(string s, int k) {
		int len = s.length();
		string ans = s;

		if (k == 1) {
			s += s;
			for (int i = 0; i < len; i++) {
				string tmp = s.substr(i, len);
				if (tmp < ans)
					ans = tmp;
			}
		} else
			sort(ans.begin(), ans.end());

		return ans;
	}
};
// @lc code=end
