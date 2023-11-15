/*
 * @lc app=leetcode id=1846 lang=cpp
 *
 * [1846] Maximum Element After Decreasing and Rearranging
 */

// @lc code=start
class Solution {
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int ret = 0;
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] >= ret + 1)
				ret++;
		return ret;
	}
};
// @lc code=end
