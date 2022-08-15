/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
/*
 * Accepted
 *  3999/3999 cases passed (15 ms)
 *  Your runtime beats 62.96 % of cpp submissions
 *  Your memory usage beats 21.24 % of cpp submissions (8.2 MB)
 */
class Solution {
	map<char, int> dict {
		{'I',	1},
		{'V',	5},
		{'X',	10},
		{'L',	50},
		{'C',	100},
		{'D',	500},
		{'M',	1000}};

public:
	int romanToInt(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i < s.size() - 1 && dict[s[i]] < dict[s[i + 1]]) {
				ans += (dict[s[i + 1]] - dict[s[i]]);
				i++;
			} else
				ans += dict[s[i]];
		}
		return ans;
	}
};
// @lc code=end
