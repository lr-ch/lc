/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		for (int i = 0; i < nums.size(); i++) {
			int j = i;

			while (j + 1 < nums.size() && nums[j] == nums[j + 1] - 1)
				j++;

			if (j + 1 != i && i != j /* the last one */)
				ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
			else
				ans.push_back(to_string(nums[i]));

			i = j;
		}
		return ans;
	}
};
// @lc code=end
