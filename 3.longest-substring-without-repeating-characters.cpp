/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<int> dict(256);
		int	length = 0;
		for (int i = 0; i < s.length(); i++) {
			fill(dict.begin(), dict.end(), 0);
			for (int j = i; j < s.length(); j++) {
				if (dict[s[j]] == 0) {
					length = max(length, j - i + 1);
					dict[s[j]] = 1;
				} else
					break;
			}
		}
		return length;
	}
};
// @lc code=end

