/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
	/*
	 * Time Limit Exceeded
	 *  35/162 cases passed (N/A)
	 */
class SolutionTLE {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int min_diff = 10000, ans;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (j == i) continue;
				for (int k = 0; k < nums.size(); k++) {
					if (k == i || k == j) continue;
					int diff = abs(nums[i] + nums[j] + nums[k] - target);
					if (min_diff > diff) {
						min_diff = diff;
						ans = nums[i] + nums[j] + nums[k];
					}
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int min_diff = INT_MAX;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (abs(min_diff) > abs(target - sum))
					min_diff = target - sum;

				if (sum > target)
					right--;
				else
					left++;
			}
		}
		return target - min_diff;
	}
};
// @lc code=end
