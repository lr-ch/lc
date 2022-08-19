/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> freq;
		for (int& i : nums) freq[i]++;

		unordered_map<int, vector<vector<int>>> decks_need_n;

		for (int& n : nums) {
			if (freq[n] == 0) continue;

			if (decks_need_n.count(n) && decks_need_n[n].size() > 0) {
				freq[n]--;

				// from decks take a deck which can concatenate n
				auto deck = decks_need_n[n].back();
				deck.push_back(n);

				// remove this deck
				decks_need_n[n].pop_back();

				// because this deck needs n + 1 now
				decks_need_n[n + 1].push_back(deck);
			} else if (freq[n] > 0 && freq[n + 1] > 0 && freq[n + 2] > 0) {
				// if no decks need n, create a new deck
				freq[  n  ]--;
				freq[n + 1]--;
				freq[n + 2]--;
				decks_need_n[n + 3].push_back({ n, n + 1, n + 2 });
			} else
				return false;
		}

		return true;
	}
};
// @lc code=end
