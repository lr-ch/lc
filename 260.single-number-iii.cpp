/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_map<int, int> freq;
		for (int& n : nums) freq[n]++;

		vector<int> ans;
		for (auto& [n, f] : freq) if (f == 1) ans.push_back(n);
		return ans;
	}
};
// @lc code=end
