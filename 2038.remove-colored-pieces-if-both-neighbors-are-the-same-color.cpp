/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

// @lc code=start
class Solution {
public:
	bool winnerOfGame(string colors) {
		int A = 0, B = 0;
		for (int i = 1; i < colors.size() - 1; i++) {
			if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
				A++;
			if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
				B++;
		}
		return A - B > 0;
	}
};
// @lc code=end
