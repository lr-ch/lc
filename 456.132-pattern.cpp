/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3) return false;

		stack<int> st;
		int init = INT_MIN;

		for (int i = nums.size() - 1; i >= 0; i--) {
			if (init > nums[i]) return true;

			while (!st.empty() && st.top() < nums[i]) {
				init = st.top();
				st.pop();
			}
			st.push(nums[i]);
		}
		return false;
	}
};
// @lc code=end
