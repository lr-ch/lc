/*
 * @lc app=leetcode id=2108 lang=cpp
 *
 * [2108] Find First Palindromic String in the Array
 */

// @lc code=start
class Solution {
public:
	string firstPalindrome(vector<string>& words) {
		auto ans = find_if(words.begin(), words.end(), [](const auto& w) {
			auto l = w.begin(), r = w.end() - 1;
			while (l < r)
				if (*l++ != *r--) return false;
			return true;
		});

		if (ans != words.end()) return *ans;
		return {};
	}
};
// @lc code=end
