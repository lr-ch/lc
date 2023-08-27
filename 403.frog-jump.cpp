/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
	// the previous jump could be anywhere, so it is a state
	bool dp(vector<int>& s, int pos, int jump) {
		if (pos == s.back()) return true;
		if (!units.count(pos)) return false;
		if (fail.count({pos, jump})) return false;

		if ((jump - 1 > 0 && dp(s, pos + jump - 1 , jump - 1)) ||
			(jump > 0 && dp(s, pos + jump, jump)) ||
			(dp(s, pos + jump + 1, jump + 1)))
			return true;

		fail.insert({pos, jump});
		return false;
	}

	struct pair_hash {
		// !!!DANGER!!! there could be collisions in some cases
		inline size_t operator()(const pair<int, int> & v) const {
			return v.first;
		}
	};

	unordered_set<int> units;
	unordered_set<pair<int, int>, pair_hash> fail;
public:
	bool canCross(vector<int>& stones) {
		for (const auto& s : stones)
			units.insert(s);

		return dp(stones, 0, 0);
	}
};
// @lc code=end
