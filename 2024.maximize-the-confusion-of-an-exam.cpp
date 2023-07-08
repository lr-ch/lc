/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
class Solution {
public:
	int maxConsecutiveAnswers(string answerKey, int k) {
		int left = 0, right = 0;
		int t = 0, f = 0;

		int ans = 0;
		while (right < answerKey.length()) {
			answerKey[right] == 'T' ? t++ : f++;

			while (t > k && f > k) {
				answerKey[left] == 'T' ? t-- : f--;
				left++;
			}
			ans = max(ans, right - left + 1);
			right++;
		}
		return ans;
	}
};
// @lc code=end
