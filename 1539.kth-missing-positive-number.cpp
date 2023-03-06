/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
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
// @lc code=end
