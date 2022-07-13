/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		vector<char> jewels_v(jewels.begin(), jewels.end());
		vector<char> stones_v(stones.begin(), stones.end());

		int sum = 0;
		for (auto i : jewels_v)
			sum += count(stones_v.begin(), stones_v.end(), i);

		return sum;
	}
};
// @lc code=end

