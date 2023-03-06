/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution1 {
public:
	int findKthPositive(vector<int>& arr, int k) {
		vector<int> missed;
		int count = 1;
		for (int i : arr) {
			while (i != count) {
				missed.push_back(count);
				if (missed.size() == k)
					return count;

				count++;
			}
			count++;
		}
		return *arr.rbegin() + k - missed.size();
	}
};

class Solution2 {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int count = 1, missed = 0;
		for (int i = 0; i < arr.size(); i++, count++) {
			if (count != arr[i]) {
				// count missing numbers
				missed += arr[i] - count;

				// collected enough k?
				if (missed >= k)
					return arr[i] - (missed - k) - 1;

				count = arr[i];
			}
		}
		return *arr.rbegin() + k - missed;
	}
};

class Solution {
	/*
	 * Accepted
	 *  84/84 cases passed (3 ms)
	 *  Your runtime beats 88.86 % of cpp submissions
	 *  Your memory usage beats 20.52 % of cpp submissions (9.8 MB)
	 */
	Solution1 sol1;

	/*
	 * Accepted
	 *  84/84 cases passed (0 ms)
	 *  Your runtime beats 100 % of cpp submissions
	 *  Your memory usage beats 38.05 % of cpp submissions (9.6 MB)
	 */
	Solution2 sol2;

public:
	int findKthPositive(vector<int>& arr, int k) {
	//	return sol1.findKthPositive(arr, k);
		return sol2.findKthPositive(arr, k);
	}
};
// @lc code=end
