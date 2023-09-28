/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		deque<int> ret;
		for (const auto& i : nums)
			if (i % 2)
				ret.push_back(i);
			else
				ret.push_front(i);
		return vector<int>(ret.begin(), ret.end());
	}
};
// @lc code=end
