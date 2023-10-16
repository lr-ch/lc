/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
	vector<int> genRow(vector<int>& curr, int rowIndex) {
		if (0 == rowIndex) return curr;

		vector<int> result(curr.size() + 1, 1);
		for (int i = 1; i < curr.size(); i++)
			result[i] = curr[i - 1] + curr[i];
		return genRow(result, rowIndex - 1);
	}

public:
	vector<int> getRow(int rowIndex) {
		vector<int> init(1, 1);
		return genRow(init, rowIndex);
	}
};
// @lc code=end
