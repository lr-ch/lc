/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int up = 1, down = 1;

		for (int i = 1; i < nums.size(); i++) {
			int diff = nums[i] - nums[i - 1];

			if (diff > 0)
				down = up + 1;
			else if (diff < 0)
				up = down + 1;

		//	cout << diff << " " << up << ":" << down << endl;
		}
		return max(up, down);
	}
};
// @lc code=end

