/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		unordered_map<int, int> freq;
		for (auto& i : arr) freq[i]++;
		for (auto& [i, n] : freq)
			if (n > arr.size() / 4)
				return i;
		return 0;
	}
};
// @lc code=end
