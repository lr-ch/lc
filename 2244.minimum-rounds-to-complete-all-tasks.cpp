/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
class SolutionBF {
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

			if (c > 0) ans++;			// can be devided again
		}

		return ans;
	}
};

class SolutionOpt {
public:
	int minimumRounds(vector<int>& tasks) {
		unordered_map<int, int> mp;			// <difficulty level, count>

		for (auto& d : tasks) mp[d]++;

		int ans = 0;
		for (auto [_, c] : mp) {
			if (c < 2) return -1;

			if (c % 3 == 0)
				ans = (c / 3) + ans;
			else
				ans = (c / 3) + ans + 1;	// can be devided again
		}

		return ans;
	}
};

class Solution {
	SolutionBF bf;
	SolutionOpt opt;
public:
	int minimumRounds(vector<int>& tasks) {
	//	return bf.minimumRounds(tasks);
		return opt.minimumRounds(tasks);
	}
};
// @lc code=end
