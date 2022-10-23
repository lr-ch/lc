/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> freq(nums.size(), 0);
		int dup = 0, lost = 0;

		for (int i : nums) freq[i - 1]++;

		for (int j = 0; j < freq.size(); j++) {
			if (freq[j] == 2) dup = j + 1;
			if (freq[j] == 0) lost = j + 1;
		}

		return { dup, lost };
	}
};
// @lc code=end
