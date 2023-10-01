/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.length(); i += k * 2) {
			int left = i;
			int right = (i + k - 1 < s.length() ?
							i + k - 1 :
							s.length() - 1 /* If there are fewer than k characters left, reverse all of them. */ );
			while (left < right)
				swap(s[left++], s[right--]);
		}
		return s;
	}
};
// @lc code=end
