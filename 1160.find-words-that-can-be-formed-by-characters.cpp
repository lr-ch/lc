/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> dict(26, 0);
		for (auto& ch : chars) dict[ch - 'a']++;

		int ans = 0;
		for (auto& word : words) {
			vector<int> wdict(26, 0);
			for (auto& cw : word) wdict[cw - 'a']++;

			bool is_good = true;
			for (int i = 0; i < 26; i++)
				if (wdict[i] > dict[i]) {
					is_good = false;
					break;
				}

			if (is_good) ans += word.length();
		}
		return ans;
	}
};
// @lc code=end
