/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		auto iter = upper_bound(letters.begin(), letters.end(), target);
		return iter == letters.end() ? letters[0] : *iter;
	}
};
// @lc code=end
