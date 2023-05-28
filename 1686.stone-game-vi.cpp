/*
 * @lc app=leetcode id=1686 lang=cpp
 *
 * [1686] Stone Game VI
 */

// @lc code=start
class Solution {
public:
	int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		vector<array<int, 3>> stoneVal;		// { value sum, alice value, bob value }
		for (int i = 0; i < aliceValues.size(); i++)
			stoneVal.push_back({ aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i] });
		sort(stoneVal.begin(), stoneVal.end(), [](const auto& a, const auto& b) {
													return a[0] > b[0];
												});
		int alice = 0, bob = 0;
		// each turn, alice and bob takes the maximun value sum for maximun profit
		for (int i = 0; i < stoneVal.size(); i++) {
			if (i % 2 == 0)		// alice's turn
				alice += stoneVal[i][1];
			else				// bob's turn
				bob += stoneVal[i][2];
		}
		return alice == bob ? 0 : alice > bob ? 1 : -1;
	}
};
// @lc code=end
