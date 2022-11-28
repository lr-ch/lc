/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
	array<int, 100001> records;
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		records.fill(-1);

		for (auto& m : matches) {
			// win record
			if (records[m[0]] == -1) records[m[0]] = 0;

			// lose record
			if (records[m[1]] == -1) records[m[1]] = 1;
			else records[m[1]]++;
		}

		vector<int> no_lose, win_once;
		for (int i = 1; i < records.size(); i++) {
			if (records[i] == 0) no_lose.push_back(i);
			if (records[i] == 1) win_once.push_back(i);
		}

		return { no_lose, win_once };
	}
};
// @lc code=end
