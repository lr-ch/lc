/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		unordered_map<char, int> init_pos;
		int ans = -1;   // default value

		for (int i = 0; i < s.length(); i++)
			if (init_pos.find(s[i]) != init_pos.end())
				ans = max(ans, i - init_pos[s[i]] - 1);
			else
				init_pos[s[i]] = i;

		return ans;
	}
};
// @lc code=end
