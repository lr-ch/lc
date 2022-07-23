/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
	/*
	 * @ref :
	 *    315. Count of Smaller Numbers After Self
	 *    912. Sort an Array
	 *    493. Reverse Pairs
	 */
	int count, lower_, upper_;
	long long *tmp;

	void merge(vector<long long>& v, int left, int mid, int right) {
		for (int i = left; i <= right; i++)
			tmp[i] = v[i];

		//+++>
		int start = mid + 1, end = mid + 1;
		for (int i = left; i < mid + 1; i++) {
			while (start <= right && tmp[start] - tmp[i] < lower_)
				start++;
			while (end <= right && tmp[end] - tmp[i] <= upper_)
				end++;
			count += end - start;
		}
		//+++<

		int i = left, j = mid + 1;
		for (int p = left; p <= right; p++)
			if (i == mid + 1)				// left part is all done
				v[p] = tmp[j++];
			else if (j == right + 1)		// right part is all done
				v[p] = tmp[i++];
			else if (tmp[i] > tmp[j])
				v[p] = tmp[j++];
			else
				v[p] = tmp[i++];
	}

	void merge_sort(vector<long long>& v, int left, int right) {
		if (left >= right) return;

		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid);
		merge_sort(v, mid + 1, right);
		merge(v, left, mid, right);
	}

public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		count = 0;
		lower_ = lower;
		upper_ = upper;
		tmp = new long long[nums.size() + 1];

		vector<long long> preSum(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			preSum[i + 1] = preSum[i] + nums[i];

		merge_sort(preSum, 0, preSum.size() - 1);

		delete [] tmp;

		return count;
	}
};
// @lc code=end

