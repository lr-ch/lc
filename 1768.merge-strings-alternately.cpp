/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		auto iter1 = word1.begin(), iter2 = word2.begin();

		string res;
		while (iter1 != word1.end() && iter2 != word2.end()) {
			res += *iter1++;
			res += *iter2++;
		}

		while (iter1 != word1.end())
			res += *iter1++;

		while (iter2 != word2.end())
			res += *iter2++;

		return res;
	}
};
// @lc code=end
