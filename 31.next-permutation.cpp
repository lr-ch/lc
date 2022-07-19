/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
	void swap(vector<int>& v, int i, int j) {
		int tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}

	void reverse(vector<int>& v, int left, int right) {
		while (left < right)
			swap(v, left++, right--);
	}

public:
	void nextPermutation(vector<int>& nums) {
		int numsLength = nums.size();

		int pivot = numsLength - 2;
		// find the pivot
		while (pivot >= 0 && nums[pivot] >= nums[pivot + 1])
			pivot--;

		// deal with corner case - decreasing sequence, e.g. [4,3,2,1]
		// reverse all element so the answer will be [1,2,3,4]
		if (pivot < 0) {
			reverse(nums, 0, numsLength - 1);
			return;
		}

		// find the maximun value at right of pivot
		int indexToSwap = pivot + 1;
		while (indexToSwap < numsLength && nums[indexToSwap] > nums[pivot])
			indexToSwap++;
		swap(nums, pivot, indexToSwap - 1);

		// reverse elements after pivot
		reverse(nums, pivot + 1, numsLength - 1);
	}
};
// @lc code=end

