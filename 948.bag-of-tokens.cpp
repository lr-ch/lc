/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int power) {
		int left = 0, right = tokens.size() - 1, score = 0, ans = 0;

		sort(tokens.begin(), tokens.end());
		while (left <= right) {
			if (tokens[left] <= power) {
				power -= tokens[left];
				score++;
				left++;
			} else if (tokens[left] > power && score > 0) {
				power += tokens[right];
				score--;
				right--;
			} else
				// since the tokens is sorted, no need to advance left for possibility
				break;

			// keep the maximun score from decreasing
			ans = max(score, ans);
		}

		return ans;
	}
};
// @lc code=end
