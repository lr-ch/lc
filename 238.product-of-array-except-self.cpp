/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> front(n, 1), back(n, 1), res(n);

		for (int i = 0; i < n - 1; i++)
			front[i + 1] = front[i] * nums[i];

		for (int i = n - 1; i > 0; i--)
			back[i - 1] = back[i] * nums[i];

		for (int i = 0; i < n; i++)
			res[i] = front[i] * back[i];

		return res;
	}
};
// @lc code=end

