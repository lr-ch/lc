/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		if (arr.size() < 3) return false;

		bool pivot = false;
		for (int i = 0; i < arr.size() - 1; i++) {
			if (i != 0 && arr[i + 1] < arr[i])
				pivot = true;

			if (pivot) {
				if (arr[i + 1] >= arr[i])
					return false;
			} else {
				if (arr[i + 1] <= arr[i])
					return false;
			}
		}
		return true && pivot;
	}
};
// @lc code=end

