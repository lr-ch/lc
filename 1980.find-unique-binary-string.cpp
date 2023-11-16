/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
class Solution {
public:
	string findDifferentBinaryString(vector<string>& nums) {
		string res;
		for (int i = 0; i < nums.size(); i++)
			res += (nums[i][i] == '1' ? '0' : '1');
		return res;
	}
};
// @lc code=end
