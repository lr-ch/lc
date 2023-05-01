/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
	double average(vector<int>& salary) {
		double sum = accumulate(salary.begin(), salary.end(), 0);
		sum -= *max_element(salary.begin(), salary.end());
		sum -= *min_element(salary.begin(), salary.end());
		return (sum / (salary.size() - 2));
	}
};
// @lc code=end
