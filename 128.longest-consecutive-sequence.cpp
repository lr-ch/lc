/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
	void PrintV(vector<int>& v) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
public:
	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
	//	PrintV(nums);

		int maxLength = 0, base = 0, mover = 0, repeatChar = 0;
		for (base = 0; base < nums.size(); base += mover - base) {
			for (mover = base + 1; mover < nums.size(); mover++)
				if (nums[mover] - nums[mover - 1] == 1)
					continue;
				else if (nums[mover] == nums[mover - 1])
					repeatChar++;
				else
					break;
	//		cout << base << " " << mover << " " << repeatChar << endl;
			maxLength = max(maxLength, mover - base - repeatChar);
			repeatChar = 0;
		}
		return maxLength;
	}
};
// @lc code=end
