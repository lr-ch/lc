/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution {
public:
	int tallestBillboard(vector<int>& rods) {
		int sum = accumulate(rods.begin(), rods.end(), 0);

		/*
		 * dp[i][j] : the common height of h1, h2 with i rods and height difference j
		 *  |--- h1 ---|
		 *  |--- h2 ---|-- j --|
		 *  dp[i][j] = min(h1, h2)
		 */
		vector<vector<int>> dp(rods.size() + 1, vector<int>(sum + 1, -1));
		dp[0][0] = 0;

		for (int i = 1; i <= rods.size(); i++) {
			int currH = rods[i - 1];
			for (int j = 0; j <= sum - currH; j++) {
				if (dp[i - 1][j] < 0) continue;

				// don't use this rod
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);

				/*
				 * put this rod on the taller side
				 *  |--- h1 ---|
				 *  |--- h2 ---|- j -|--- currH ---|
				 */
				dp[i][j + currH] = max(dp[i][j + currH], dp[i - 1][j]);

				/*
				 * put this rod on the shorter side
				 * two cases :
				 * 1.
				 *  |--- h1 ---|-- currH --|
				 *  |--- h2 ---|------ j ------|
				 *  common height = dp[i - 1][j] + currH, diff = j - currH
				 *
				 * 2.
				 *  |--- h1 ---|-- currH --|
				 *  |--- h2 ---|--- j ---|
				 *  common height = dp[i - 1][j] + j, diff = currH - j
				 */
				dp[i][abs(j - currH)] = max(dp[i][abs(j - currH)], dp[i - 1][j] + min(j, currH));
			}
		}
		return dp[rods.size()][0];
	}
};
// @lc code=end
