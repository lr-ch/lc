/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution {
	bool validatePairsCount(const vector<int>& n, int t, int p) {
		int count = 0;
		for (int i = 1; i < n.size(); i++) {
			if (t >= n[i] - n[i - 1]) {
				count++;
				i++;	// count pairs, so i jumps by 2
			}
		}
		return count >= p;
	}

public:
	int minimizeMax(vector<int>& nums, int p) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.back() - nums.front() + 1;

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (validatePairsCount(nums, mid, p))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};
// @lc code=end
