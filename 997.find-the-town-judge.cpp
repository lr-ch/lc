/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> trusted(n, 0);		// trusted[i] = amount of people trust folk#i
		vector<int> to_trust(n, 0);		// to_trust[i] = folk#i trusts amount of people

		for (const auto& t : trust) {
			trusted[t[1] - 1]++;
			to_trust[t[0] - 1]++;
		}

		for (int i = 0; i < n; i++)
			if (trusted[i] == n - 1 && to_trust[i] == 0)
				return i + 1;

		return -1;
	}
};
// @lc code=end

