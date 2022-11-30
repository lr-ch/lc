/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
	map<int, int> occur;
public:
	bool uniqueOccurrences(vector<int>& arr) {
		for (auto& i : arr) occur[i]++;

		bitset<1000> inv;
		for (auto& [_, freq] : occur) {
			if (inv[freq] == 1) return false;
			inv[freq] = 1;
		}
		return true;
	}
};
// @lc code=end
