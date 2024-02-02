/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> ans;

		for (int i = 1; i <= 9; i++) {
			int num = i;

			for (int bit = i + 1; num <= high && bit <= 10; bit++) {
				if (num >= low) ans.push_back(num);
				num = num * 10 + bit;
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};
// @lc code=end
