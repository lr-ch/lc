/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) {
			return s1.length() < s2.length();
		});

		int result = 1;
		unordered_map<string, int> dp;

		for (string word : words) {
			for (int i = 0; i < word.size(); i++) {
				string pred = word.substr(0, i) + word.substr(i + 1);
				dp[word] = max(
							dp[word],
							dp.find(pred) == dp.end() ?
								1 : dp[pred] + 1
							);
			}
			result = max(result, dp[word]);
		}
		return result;
    }
};
// @lc code=end

