/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

// @lc code=start
class Solution {
public:
	vector<int> findArray(vector<int>& pref) {
		int prev = 0;
		for (auto& num : pref)
			prev ^= (num ^= prev);
		return pref;
	}
};
// @lc code=end
