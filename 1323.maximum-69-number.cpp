/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
	int maximum69Number (int num) {
		string strnum = to_string(num);
		int ans = num;
		for (int i = 0; i < strnum.length(); i++) {
			if (strnum[i] == '9') continue;
			strnum[i] = '9';
			ans = max(stoi(strnum), ans);
			strnum[i] = '6';
		}
		return ans;
	}
};
// @lc code=end
