/*
 * @lc app=leetcode id=2971 lang=cpp
 *
 * [2971] Find Polygon With the Largest Perimeter
 */

// @lc code=start
class Solution {
public:
	long long largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);

		while (nums.size() > 0) {
			if (sum - nums.back() > nums.back())
				break;
			sum -= nums.back();
			nums.pop_back();
		}

		return nums.size() >= 3 ? sum : -1;
	}
};
// @lc code=end
