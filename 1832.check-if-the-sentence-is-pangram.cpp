/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
	array<int, 26> freq;
public:
	bool checkIfPangram(string sentence) {
		for (auto& c : sentence) freq[c - 'a']++;
		for (auto& i : freq) if (!i) return false;
		return true;
	}
};
// @lc code=end
