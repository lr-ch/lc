/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		return reduce(word1.begin(), word1.end()) == reduce(word2.begin(), word2.end());
	}
};
// @lc code=end

