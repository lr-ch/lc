/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
	int target;

	bool combine(vector<int>& m, int used, int up, int right, int down, int left)
	{
		// if all matchsticks are used, check length of each side
		if (m.size() == used)
			return up == target && right == target && down == target && left == target;

		// try to add up side
		if (up + m[used] <= target)
			if (combine(m, used + 1, up + m[used], right, down, left))
				return true;

		// try to add right side
		if (right + m[used] <= target)
			if (combine(m, used + 1, up, right + m[used], down, left))
				return true;

		// try to add down side
		if (down + m[used] <= target)
			if (combine(m, used + 1, up, right, down + m[used], left))
				return true;

		// try to add left side
		if (left + m[used] <= target)
			if (combine(m, used + 1, up, right, down, left + m[used]))
				return true;

		return false;
	}

public:
	bool makesquare(vector<int>& matchsticks) {
		// impossible if total length can not be divided by 4
		int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (sum % 4) return false;

		// length of each side must be equal to sum / 4
		target = sum / 4;
		sort(matchsticks.begin(), matchsticks.end(), greater<int>());
		return combine(matchsticks, 0, 0, 0, 0, 0);
	}
};
// @lc code=end

