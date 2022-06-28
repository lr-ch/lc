/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution {
public:
	int minDeletions(string s) {
		vector<int> alphaOccur(26, 0);
		for (auto c : s)
			alphaOccur[c - 'a']++;

		sort(alphaOccur.begin(), alphaOccur.end(), [](const auto& a, const auto& b) {
			return a > b;
		});

		int maxVal = alphaOccur[0];
		int	counter = 0;
		for (auto val : alphaOccur) {
			if (maxVal < val) {
				if (maxVal > 0)
					// the maxVal already decreased by 1,
					// so the val will not be the same as previous
					counter += (val - maxVal);
				else
					// already zero, must be totally removed
					counter += val;
			}
			maxVal = min(maxVal - 1, val - 1);
		}

		return counter;
	}
};
// @lc code=end

