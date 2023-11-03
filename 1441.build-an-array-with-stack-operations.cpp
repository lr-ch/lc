/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ans;
		int cur = 1;
		for (int& n : target) {
			while (cur < n) {
				ans.push_back("Push");
				ans.push_back("Pop");
				cur++;
			}
			ans.push_back("Push");
			cur++;
		}
		return ans;
	}
};
// @lc code=end
