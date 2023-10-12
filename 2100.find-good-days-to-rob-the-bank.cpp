/*
 * @lc app=leetcode id=2100 lang=cpp
 *
 * [2100] Find Good Days to Rob the Bank
 */

// @lc code=start
class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int S = security.size();
		vector<int>	dec(S, 0),	// dec[i] := days of security decreases before day-i
					inc(S, 0);	// inc[i] := days of security increases after day-i

		for (int i = 1; i < S; i++)
			if (security[i - 1] >= security[i])
				dec[i] = dec[i - 1] + 1;

		for (int i = S - 2; i >= 0; i--)
			if (security[i] <= security[i + 1])
				inc[i] = inc[i + 1] + 1;

		vector<int> ans;
		for (int i = time; i < S - time; i++)
			if (dec[i] >= time && inc[i] >= time)
				ans.push_back(i);

		return ans;
	}
};
// @lc code=end
