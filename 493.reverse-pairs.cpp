/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 * 	 32/136 cases passed (N/A)
	 */
/*
	int reversePairs(vector<int>& nums) {
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++)
				if ((long long)nums[i] > (long long)nums[j] * 2)
					count++;

		return count;
	}
*/

	/*
	 * @ref :
	 *    315. Count of Smaller Numbers After Self
	 *    912. Sort an Array
	 */
	int *tmp;
	int count;

	void merge(vector<int>& v, int left, int mid, int right) {
		for (int i = left; i <= right; i++)
			tmp[i] = v[i];

		//++>
		int fence = mid + 1;	// start of right part
		for (int j = left; j < mid + 1; j++) {
			// the right part is sorted, only need to find the
			// last tmp[fence] matches condition, remaining elements
			// behind can be ignored
			while (fence <= right &&
					(long long)tmp[j] > (long long)tmp[fence] * 2)
				fence++;
			count += fence - (mid + 1);
		}
		//++<

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

	void merge_sort(vector<int>& v, int left, int right) {
		if (left >= right) return;

		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid);
		merge_sort(v, mid + 1, right);
		merge(v, left, mid, right);
	}

public:
	int reversePairs(vector<int>& nums) {
		tmp = new int[nums.size()];
		count = 0;
		merge_sort(nums, 0, nums.size() - 1);
		delete [] tmp;

		return count;
	}
};
// @lc code=end

