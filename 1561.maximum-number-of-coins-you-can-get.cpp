/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution {
public:
	int maxCoins(vector<int>& piles) {
		sort(piles.begin(), piles.end());

		int for_bob = piles.size() / 3;
		int for_me = 0, for_alice = 0;

		/*
		 *  2, 4, 5
		 *  B  M  A
		 *
		 *  1, 2, 2, 4, 7, 8
		 *  B  B  M  A  M  A
		 *
		 *  Bob always takes least, me and alice takes from largest
		 *  and 2nd largest every turn
		 */
		for (int i = 0; i < piles.size(); i++) {
			if (i < for_bob) continue;

			if ((i - for_bob) % 2 == 0)
				for_me += piles[i];

			if ((i - for_bob) % 2 != 0)
				for_alice += piles[i];
		}

		return for_me;
	}
};
// @lc code=end
