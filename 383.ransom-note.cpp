/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		array<int, 26> char_map;
		fill(char_map.begin(), char_map.end(), 0);
		for (char& ch : magazine) char_map[ch - 'a']++;

		for (char& r : ransomNote)
			if (char_map[r - 'a'] > 0) char_map[r - 'a']--;
			else return false;

		return true;
	}
};
// @lc code=end

