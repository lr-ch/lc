/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
class Solution {
	const int MOD = 1e9 + 7;
	array<array<long, 101>, 101> dp;	// dp[i][j] -> playlists number of length i with j different songs
public:
	int numMusicPlaylists(int n, int goal, int k) {
		dp[0][0] = 1;

		for (int i = 1; i <= goal; i++)
			for (int j = 1; j <= min(i, n); j++)
				dp[i][j] =
					// add a new song #j, j - 1 songs used, choose from (n - (j - 1)) songs
					(dp[i - 1][j - 1] * (n - (j - 1)) +
					// no new song added, reuse selected songs from j - k, 0 if j < k
					dp[i - 1][j] * (max(j - k, 0))) %
					MOD;

		return dp[goal][n];
	}
};
// @lc code=end
