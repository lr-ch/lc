/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while (i != j) {
			if (numbers[i] + numbers[j] < target) {
				i++;
			} else if (numbers[i] + numbers[j] > target) {
				j--;
			} else {
				break;	// numbers[i] + numbers[j] == target
			}
		}
		// the index is 1-based...
		return vector<int>{i + 1, j + 1};
	}
};
// @lc code=end

