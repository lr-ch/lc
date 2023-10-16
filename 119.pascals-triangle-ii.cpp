/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class SolutionRecur {
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

class SolutionTab {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> curr(1, 1);
		for (int n = 0; n < rowIndex; n++) {
			vector<int> next(curr.size() + 1, 1);
			for (int i = 1; i < curr.size(); i++)
				next[i] = curr[i - 1] + curr[i];
			curr = next;
		}
		return curr;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 34/34 cases passed (3 ms)
	 *  - Your runtime beats 36.93 % of cpp submissions
	 *  - Your memory usage beats 7.53 % of cpp submissions (7.2 MB)
	 */
	SolutionRecur recur;

	/*
	 * Accepted
	 *  - 34/34 cases passed (3 ms)
	 *  - Your runtime beats 36.93 % of cpp submissions
	 *  - Your memory usage beats 11.01 % of cpp submissions (7.1 MB)
	 */
	SolutionTab tab;
public:
	vector<int> getRow(int rowIndex) {
	//	return recur.getRow(rowIndex);
		return tab.getRow(rowIndex);
	}
};
// @lc code=end
