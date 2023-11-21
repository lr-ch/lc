/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
	inline int rev(int n) {
		string str_n = to_string(n), str_rev_n = string(str_n.rbegin(), str_n.rend());
		return atoi(str_rev_n.c_str());
	}

	const int MOD = 1e9 + 7;
public:
	int countNicePairs(vector<int>& nums) {
		unordered_map<int, int> dict;
		int count = 0;

		for (auto& n : nums) {
			int r = rev(n);
			if (dict.count(n - r)) {
				count += dict[n - r] % MOD;
				count %= MOD;
			}
			dict[n - r]++;
		}
		return count;
	}
};
// @lc code=end
