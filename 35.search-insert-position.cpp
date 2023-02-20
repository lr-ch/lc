/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class SolutionStdLib {
public:
	int searchInsert(vector<int>& nums, int target) {
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};

class SolutionDIY {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return left;
	}
};

class Solution {
	/*
	 * Accepted
	 *  * 64/64 cases passed (0 ms)
	 *  * Your runtime beats 100 % of cpp submissions
	 *  * Your memory usage beats 31.02 % of cpp submissions (9.8 MB)
	 */
	SolutionStdLib std;

	/*
	 * Accepted
	 *  * 64/64 cases passed (10 ms)
	 *  * Your runtime beats 22.58 % of cpp submissions
	 *  * Your memory usage beats 31.02 % of cpp submissions (9.7 MB)
	 */
	SolutionDIY diy;
public:
	int searchInsert(vector<int>& nums, int target) {
	//	return std.searchInsert(nums, target);
		return diy.searchInsert(nums, target);
	}
};
// @lc code=end
