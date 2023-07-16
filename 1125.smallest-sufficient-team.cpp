/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
class Solution {
	typedef bitset<16> skillset;
public:
	vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		vector<skillset> person_skills(people.size(), 0);
		for (int i = 0; i < people.size(); i++)
			for (int j = 0; j < req_skills.size(); j++)
				person_skills[i][j] = find(
										people[i].begin(),
										people[i].end(),
										req_skills[j]) != people[i].end() ? 1 : 0;

		unordered_map<skillset, vector<int>> dp;
		dp[0] = {};

		for (int i = 0; i < person_skills.size(); i++) {
			unordered_map<skillset, vector<int>> tmp(dp);
			for (const auto& [skills, team] : dp) {
				skillset skill_added = skills | person_skills[i];
				if (!tmp.count(skill_added) || team.size() + 1 < tmp[skill_added].size()) {
					tmp[skill_added] = team;
					tmp[skill_added].push_back(i);
				}
			}
			dp = move(tmp);
		}

		return dp[(1 << req_skills.size()) - 1];
	}
};
// @lc code=end
