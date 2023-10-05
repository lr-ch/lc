/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int a = 0, b = 0, count1 = 0, count2 = 0;
		for (const auto& n : nums) {
			if (n == a) count1++;
			else if (n == b) count2++;
			else if (0 == count1) {
				a = n;
				count1 = 1;
			} else if (0 == count2) {
				b = n;
				count2 = 1;
			} else {
				count1--;
				count2--;
			}
		}

		// validation
		count1 = 0;
		count2 = 0;
		for (const auto& n : nums) {
			if (n == a) count1++;
			if (n == b) count2++;
		}

		vector<int> ans;
		if (count1 > nums.size() / 3) ans.push_back(a);
		if (count2 > nums.size() / 3 && a != b) ans.push_back(b);
		return ans;
	}
};
// @lc code=end
