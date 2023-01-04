/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		unordered_map<int, int> mp;		// <difficulty level, count>

		for (auto& d : tasks) mp[d]++;

		int ans = 0;
		for (auto [_, c] : mp) {
			if (c < 2) return -1;

			while (c >= 3) {
				c -= 3;
				ans++;
			}

			if (c > 0) ans++;	// can be devided again
		}

		return ans;
	}
};
// @lc code=end
