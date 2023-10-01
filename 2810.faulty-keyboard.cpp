/*
 * @lc app=leetcode id=2810 lang=cpp
 *
 * [2810] Faulty Keyboard
 */

// @lc code=start
class Solution {
public:
	string finalString(string s) {
		string ans;
		for (const auto& ch : s)
			if (ch != 'i')
				ans.push_back(ch);
			else
				reverse(ans.begin(), ans.end());
		return ans;
	}
};
// @lc code=end
