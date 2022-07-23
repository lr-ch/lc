/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
	void merge(vector<int>& v, int left, int mid, int right, vector<int>& t) {
		// copy original array to another copy
		for (int i = left; i <= right; i++)
			t[i] = v[i];

		// use double pointer to merge the result from t to v
		int p = left, q = mid + 1;
		for (int j = left; j <= right; j++) {
			if (p == mid + 1)			// left part is all done
				v[j] = t[q++];
			else if (q == right + 1)	// right part is all done
				v[j] = t[p++];
			else if (t[p] < t[q])
				v[j] = t[p++];
			else
				v[j] = t[q++];
		}
	}

	void merge_sort(vector<int>& v, int left, int right, vector<int>& t) {
		if (left >= right) return;

		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid, t);
		merge_sort(v, mid + 1, right, t);
		merge(v, left, mid, right, t);
	}
public:
	vector<int> sortArray(vector<int>& nums) {
		vector<int> tmp(nums.size());
		merge_sort(nums, 0, nums.size() - 1, tmp);

		return nums;
	}
};
// @lc code=end

