/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> tmp;
		for (auto& m : matrix)
			tmp.insert(tmp.end(), m.begin(), m.end());
		sort(tmp.begin(), tmp.end());
		return tmp[k - 1];
	}
};
// @lc code=end

