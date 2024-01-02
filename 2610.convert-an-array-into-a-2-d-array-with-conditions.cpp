/*
 * @lc app=leetcode id=2610 lang=cpp
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> findMatrix(vector<int>& nums) {
		unordered_map<int, int> freq;
		int maxCount = 0;
		for (auto& n : nums) {
			freq[n]++;
			maxCount = max(maxCount, freq[n]);
		}

		vector<vector<int>> ans(maxCount);
		for (auto& [num, count] : freq)
			for (int i = 0; i < count; i++)
				ans[i].push_back(num);

		return ans;
	}
};
// @lc code=end
