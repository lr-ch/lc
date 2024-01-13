/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */

// @lc code=start
class Solution {
public:
	int minSteps(string s, string t) {
		unordered_map<char, int> count;
		for (int i = 0; i < s.length(); i++) {
			count[s[i]]++;
			count[t[i]]--;
		}

		int ans = 0;
		for (auto& [_, freq] : count)
			ans += max(0, freq);
		return ans;
	}
};
// @lc code=end
