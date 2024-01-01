/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
public:
	bool makeEqual(vector<string>& words) {
		unordered_map<char, int> freq;
		for (auto& w : words)
			for (auto& ch : w)
				freq[ch]++;
		for (auto& [_, count] : freq)
			if (count % words.size())
				return false;
		return true;
	}
};
// @lc code=end
