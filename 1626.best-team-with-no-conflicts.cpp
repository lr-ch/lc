/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		vector<pair<int, int>> players(scores.size());
		for (int i = 0; i < players.size(); i++) players[i] = { ages[i], scores[i] };
		sort(players.begin(), players.end());

		vector<int> dp(players.size(), 0);	// dp[i] -> the max score if i-th player is selected
		int res = 0;
		for (int i = 0; i < players.size(); i++) {
			dp[i] = players[i].second;
			for (int j = 0; j < i; j++) {
				// note1. player[j] is younger than player[i]
				// note2. a conflict exists if a younger player has a strictly higher score than an older player.
				// note3. so player[i] should have more or the same score than player[j]
				if (players[j].second <= players[i].second) {
						dp[i] = max(dp[i], dp[j] + players[i].second);
				}
			}
			res = max(res, dp[i]);
		}

		return res;
	}
};
// @lc code=end
