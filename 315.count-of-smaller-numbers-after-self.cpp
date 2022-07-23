/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
	// @ref : 912. Sort an Array (merge sort)
	vector<pair<int, int>> tmp;
	vector<int> result;

	void merge(vector<pair<int, int>>& v, int left, int mid, int right) {
		for (int i = left; i <= right; i++)
			tmp[i] = v[i];

		int i = left, j = mid + 1;
		for (int p = left; p <= right; p++) {
			if (i == mid + 1) {				// left part is all done
				v[p] = tmp[j++];
			} else if (j == right + 1) {	// right part is all done
				v[p] = tmp[i++];
				result[v[p].second] += j - mid - 1;
			} else if (tmp[i].first > tmp[j].first) {
				v[p] = tmp[j++];
			} else {
				v[p] = tmp[i++];
				result[v[p].second] += j - mid - 1;
			}
		}
	}

	void merge_sort(vector<pair<int, int>>& v, int left, int right) {
		if (left >= right) return;

		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid);
		merge_sort(v, mid + 1, right);
		merge(v, left, mid, right);
	}

public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<pair<int, int>> val_idx;
		for (int i = 0; i < nums.size(); i++)
			val_idx.push_back(pair<int, int>(nums[i], i));

		tmp.reserve(val_idx.size());
		result.assign(nums.size(), 0);

		merge_sort(val_idx, 0, val_idx.size() - 1);
		return result;
	}
};
// @lc code=end

